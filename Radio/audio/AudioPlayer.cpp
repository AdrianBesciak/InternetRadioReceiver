#include "AudioPlayer.hpp"
#include <cmath>
#include <cstring>
#include <mutex>
#include <stm32746g_discovery_audio.h>
#include <audio/except/player/AudioPlayerException.hpp>
#include <sdram/sdram.hpp>
#include <sys/except/SingleInstanceException.hpp>

// DMA handlers
extern "C" {
    extern SAI_HandleTypeDef haudio_out_sai;
    void AUDIO_OUT_SAIx_DMAx_IRQHandler() {
        HAL_DMA_IRQHandler(haudio_out_sai.hdmatx);
    }
}

namespace audio {
    class Handlers {
    public:
        static void handleError() {
            AudioPlayer::instance->handleError();
        }
        static void handleBufferHalfWay() {
            AudioPlayer::instance->handleBufferHalfWay();
        }
        static void handleBufferDone() {
            AudioPlayer::instance->handleBufferDone();
        }
    };
}

extern "C" {
    void BSP_AUDIO_OUT_Error_CallBack(void) {
        audio::Handlers::handleError();
    }
    void BSP_AUDIO_OUT_HalfTransfer_CallBack(void) {
        audio::Handlers::handleBufferHalfWay();
    }
    void BSP_AUDIO_OUT_TransferComplete_CallBack() {
        audio::Handlers::handleBufferDone();
    }
}

namespace audio {
    constexpr std::size_t PLAYER_BUFFER_SIZE = 8192;

    std::uint32_t normalizedVolume(std::uint32_t volume) {
        return static_cast<std::uint32_t>(std::round(0.7F * static_cast<float>(volume)));
    }

    AudioPlayer::AudioPlayer()
        : DelayTask("IRR_AudioPlayer", 1)
        , state(State::NO_SOURCE)
        , bufferState(BufferState::None)
        , volume(100)
        , reader()
        , playingBuffer(PLAYER_BUFFER_SIZE) {
        if (instance != nullptr)
            throw sys::SingleInstanceException("AudioPlayer instance already exists");
        instance = this;
        clearBuffer();
        playerInitialize();
    }

    AudioPlayer::~AudioPlayer() {
        if (state != State::NO_SOURCE)
            stop();
        instance = nullptr;
    }

    void AudioPlayer::setSource(const std::shared_ptr<AudioReader> &reader) {
        if (reader == this->reader)
            return;
        bool wasPlaying = isPlaying();
        if (isPlaying() || isPaused())
            playerStop();
        std::lock_guard<sys::Mutex> guard(readerMutex);
        this->reader = reader;
        updateState(State::STOPPED);
        clearBuffer();
        if (onMediumChanged != nullptr)
            onMediumChanged(this->reader->getName());
        if (onProgressChanged != nullptr)
            onProgressChanged(getCurrentTime(), getEndTime());
        if (wasPlaying)
            play();
    }

    void AudioPlayer::unloadSource() {
        if (isEmpty())
            return;
        playerStop();
        updateState(State::NO_SOURCE);
        reader = nullptr;
        if (onMediumChanged != nullptr)
            onMediumChanged({});
        if (onProgressChanged != nullptr) {
            onProgressChanged(0.0f, 0.0f);
        }
    }

    void AudioPlayer::play() {
        validateNotEmpty();

        if (isPaused()) {
            playerUnpause();
            updateState(State::PLAYING);
            return;
        }
        if (isPlaying())
            return;
        updateState(State::PLAYING);
        bufferState = BufferState::Started;
    }

    void AudioPlayer::pause() {
        validateNotEmpty();

        if (isPaused()) {
            playerUnpause();
            updateState(State::PLAYING);
            return;
        }
        if (isStopped())
            return;
        playerPause();
        updateState(State::PAUSED);
    }

    void AudioPlayer::stop() {
        validateNotEmpty();
        if (isStopped())
            return;
        playerStop();
        updateState(State::STOPPED);
        seek(0.0F);
    }

    void AudioPlayer::seek(float time) {
        if (isEmpty()) {
            return;
        }
        if (time > getEndTime())
            throw AudioPlayerException("Invalid time value - greater than maximal time : (" + std::to_string(time) + "/" + std::to_string(getEndTime()) + ")");
        if (!reader->isRandomAccess()) {
            return;
        }
        reader->seek(time);
        if (onProgressChanged != nullptr)
            onProgressChanged(getCurrentTime(), getEndTime());
    }

    std::string AudioPlayer::getSource() const {
        if (reader != nullptr) {
            return reader->getName();
        }
        return {};
    }

    unsigned AudioPlayer::getVolume() const {
        return volume;
    }

    void AudioPlayer::setVolume(unsigned volume) {
        if (this->volume == volume)
            return;
        if (volume > 100)
            throw AudioPlayerException("Volume cannot be greater than 100");

        this->volume = volume;
        if (state == State::PLAYING)
            playerSetVolume();

        if (onVolumeChanged != nullptr)
            onVolumeChanged(getVolume());
    }

    bool AudioPlayer::isEmpty() const {
        return state == State::NO_SOURCE;
    }

    bool AudioPlayer::isPlaying() const {
        return state == State::PLAYING;
    }

    bool AudioPlayer::isPaused() const {
        return state == State::PAUSED;
    }

    bool AudioPlayer::isStopped() const {
        return state == State::STOPPED;
    }

    AudioPlayer::State AudioPlayer::getState() const {
        return state;
    }

    float AudioPlayer::getCurrentTime() const {
        if (reader == nullptr) {
            return 0.0f;
        }
        return reader->getCurrentTime();
    }

    float AudioPlayer::getEndTime() const {
        if (reader == nullptr) {
            return 0.0f;
        }
        return reader->getEndTime();
    }

    void AudioPlayer::setOnStateChanged(const std::function<void(State)> &onStateChanged) {
        this->onStateChanged = onStateChanged;
    }

    void AudioPlayer::setOnProgressChanged(const std::function<void(float, float)> &onProgressChanged) {
        this->onProgressChanged = onProgressChanged;
    }

    void AudioPlayer::setOnMediumChanged(const std::function<void(const std::string &)> &onMediumChanged) {
        this->onMediumChanged = onMediumChanged;
    }

    void AudioPlayer::setOnVolumeChanged(const std::function<void(unsigned)> &onVolumeChanged) {
        this->onVolumeChanged = onVolumeChanged;
    }

    void AudioPlayer::setOnFinished(const std::function<void()> &onFinished) {
        this->onFinished = onFinished;
    }

    void AudioPlayer::setOnError(const std::function<void(const std::exception &)> &onError) {
        this->onError = onError;
    }


    void AudioPlayer::executeIteration() {
        try {
            if (!isPlaying())
                return;
            std::lock_guard<sys::Mutex> guard(readerMutex);
            if (bufferState == BufferState::Error) {
                playerInitialize();
            }
            if (bufferState == BufferState::None) {
                return;
            }

            std::size_t count = 0;
            if (bufferState == BufferState::Started) {
                bufferState = BufferState::None;
                count = reader->readNext(playingBuffer.data(), PLAYER_BUFFER_SIZE);
                playerSetFrequency();
                playerSetVolume();
                playerPlayBuffer();
                if (onProgressChanged != nullptr)
                    onProgressChanged(getCurrentTime(), getEndTime());
            } else if (bufferState == BufferState::HalfWayThrough) {
                bufferState = BufferState::None;
                count = reader->readNext(playingBuffer.data(), PLAYER_BUFFER_SIZE / 2);
                if (onProgressChanged != nullptr)
                    onProgressChanged(getCurrentTime(), getEndTime());
                if (bufferState != BufferState::HalfWayThrough) {
                    std::printf("[AudioPlayer] Can't keep up\n");
                }
            } else if (bufferState == BufferState::Done) {
                bufferState = BufferState::None;
                count = reader->readNext(playingBuffer.data() + PLAYER_BUFFER_SIZE / 2,
                                         PLAYER_BUFFER_SIZE / 2);
                if (onProgressChanged != nullptr)
                    onProgressChanged(getCurrentTime(), getEndTime());
                if (bufferState != BufferState::Done) {
                    std::printf("[AudioPlayer] Can't keep up\n");
                }
            }
            if (count == 0) {
                bufferState = BufferState::None;
                unloadSource();
                if (onFinished != nullptr) {
                    onFinished();
                }
            }
        }
        catch (std::exception &exc) {
            if (onError != nullptr) {
                onError(exc);
            }
            unloadSource();
        }
    }


    void AudioPlayer::updateState(AudioPlayer::State state) {
        if (state == this->state)
            return;
        this->state = state;
        if (onStateChanged != nullptr)
            onStateChanged(this->state);
    }

    void AudioPlayer::playerInitialize() {
        if (BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, normalizedVolume(volume),22050) != AUDIO_OK)
            throw AudioPlayerException("Failed to initialize audio player for '" + reader->getName() + "'");
    }

    void AudioPlayer::playerSetFrequency() {
        BSP_AUDIO_OUT_SetFrequency(reader->getMetadata().getSamplingRate() / 2);
    }

    void AudioPlayer::playerStop() {
        if (BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW) != AUDIO_OK)
            throw AudioPlayerException("Failed to stop audio player for '" + reader->getName() + "'");
        bufferState = BufferState::Done;
    }

    void AudioPlayer::playerPlayBuffer() {
        if (BSP_AUDIO_OUT_Play(reinterpret_cast<std::uint16_t*>(playingBuffer.data()), PLAYER_BUFFER_SIZE * 2) != AUDIO_OK)
            throw AudioPlayerException("Failed to play audio from '" + reader->getName() + "'");
    }

    void AudioPlayer::playerSetVolume() {
        if (BSP_AUDIO_OUT_SetVolume(static_cast<std::uint8_t>(normalizedVolume(volume))) != AUDIO_OK)
            throw AudioPlayerException("Failed to play volume from '" + reader->getName() + "'");
    }

    void AudioPlayer::playerPause() {
        if (BSP_AUDIO_OUT_Pause() != AUDIO_OK)
            throw AudioPlayerException("Failed to pause playing for '" + reader->getName() + "'");
    }

    void AudioPlayer::playerUnpause() {
        if (BSP_AUDIO_OUT_Resume() != AUDIO_OK)
            throw AudioPlayerException("Failed to unpause playing for '" + reader->getName() + "'");
    }

    void AudioPlayer::handleError() {
        bufferState = BufferState::Error;
        std::printf("[AudioPlayer] Buffer error occurred\n");
    }

    void AudioPlayer::handleBufferHalfWay() {
        clearLeftPartBuffer();
        bufferState = BufferState::HalfWayThrough;
    }

    void AudioPlayer::handleBufferDone() {
        clearRightPartBuffer();
        bufferState = BufferState::Done;
    }

    void AudioPlayer::validateNotEmpty() const {
        if (isEmpty())
            throw std::logic_error("No audio source provided");
    }


    void AudioPlayer::clearLeftPartBuffer() {
        std::memset(playingBuffer.data(), 0, playingBuffer.size() * sizeof(*playingBuffer.data()) / 2);
    }

    void AudioPlayer::clearRightPartBuffer() {
        std::memset(playingBuffer.data() + playingBuffer.size() / 2, 0, playingBuffer.size() * sizeof(*playingBuffer.data()) / 2);
    }

    void AudioPlayer::clearBuffer() {
        std::memset(playingBuffer.data(), 0, playingBuffer.size() * sizeof(*playingBuffer.data()));
    }


    AudioPlayer *AudioPlayer::instance = nullptr;
}
