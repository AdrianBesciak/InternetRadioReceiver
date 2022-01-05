#include "AudioPlayer.hpp"
#include <cmath>
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
    std::uint32_t normalizedVolume(std::uint32_t volume) {
        return static_cast<std::uint32_t>(std::round(0.7F * static_cast<float>(volume)));
    }

    AudioPlayer::AudioPlayer()
        : DelayTask("IRR_AudioPlayer", 2)
        , state(State::NO_SOURCE)
        , bufferState(BufferState::None)
        , volume(100)
        , reader()
        , playingBuffer(reinterpret_cast<std::int16_t*>(sdram::addr::PLAYER_BUFFER)) {
        if (instance != nullptr)
            throw sys::SingleInstanceException("AudioPlayer instance already exists");
        instance = this;
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
            playerDeinitialize();
        this->reader = reader;
        updateState(State::STOPPED);

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
        stop();
        updateState(State::NO_SOURCE);
        if (onMediumChanged != nullptr)
            onMediumChanged(reader->getName());
        reader = nullptr;
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
        playerInitialize();
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
        playerDeinitialize();
        updateState(State::STOPPED);
        seek(0.0F);
    }

    void AudioPlayer::seek(float time) {
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
        return reader->getCurrentTime();
    }

    float AudioPlayer::getEndTime() const {
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

    void AudioPlayer::executeIteration() {
        if (!isPlaying())
            return;
        if (bufferState == BufferState::Error)
            throw AudioPlayerException("Error occurred while playing '" + reader->getName() + "'");
        if (bufferState == BufferState::None) {
            return;
        }

        std::size_t count = 0;
        if (bufferState == BufferState::Started) {
            count = reader->readNext(playingBuffer, sdram::size::PLAYER_BUFFER_SIZE);
            playerPlayBuffer();
            if (onProgressChanged != nullptr)
                onProgressChanged(getCurrentTime(), getEndTime());
            bufferState = BufferState::None;
        }
        else if (bufferState == BufferState::HalfWayThrough) {
            count = reader->readNext(playingBuffer, sdram::size::PLAYER_BUFFER_SIZE / 2);
            if (onProgressChanged != nullptr)
                onProgressChanged(getCurrentTime(), getEndTime());
            bufferState = BufferState::None;
        }
        else if (bufferState == BufferState::Done) {
            count = reader->readNext(playingBuffer + sdram::size::PLAYER_BUFFER_SIZE / 2, sdram::size::PLAYER_BUFFER_SIZE / 2);
            if (onProgressChanged != nullptr)
                onProgressChanged(getCurrentTime(), getEndTime());
            bufferState = BufferState::None;
        }
        if (count == 0) {
            bufferState = BufferState::None;
            unloadSource();
        }
    }

    void AudioPlayer::playerInitialize() {
        if (BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE, static_cast<std::uint8_t>(normalizedVolume(volume)),
                               reader->getMetadata().getSamplingRate() / 2) != AUDIO_OK)
            throw AudioPlayerException("Failed to playerInitialize audio player for '" + reader->getName() + "'");
    }

    void AudioPlayer::playerDeinitialize() {
        if (BSP_AUDIO_OUT_Stop(CODEC_PDWN_HW) != AUDIO_OK)
            throw AudioPlayerException("Failed to stop audio player for '" + reader->getName() + "'");
        bufferState = BufferState::Done;
    }

    void AudioPlayer::playerPlayBuffer() {
        if (BSP_AUDIO_OUT_Play(reinterpret_cast<std::uint16_t*>(playingBuffer), sdram::size::PLAYER_BUFFER_SIZE_BYTES) != AUDIO_OK)
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
    }

    void AudioPlayer::handleBufferHalfWay() {
        bufferState = BufferState::HalfWayThrough;
    }

    void AudioPlayer::handleBufferDone() {
        bufferState = BufferState::Done;
    }

    void AudioPlayer::validateNotEmpty() const {
        if (isEmpty())
            throw AudioPlayerException("No audio source provided");
    }

    AudioPlayer *AudioPlayer::instance = nullptr;

    void AudioPlayer::updateState(AudioPlayer::State state) {
        if (state == this->state)
            return;
        this->state = state;
        if (onStateChanged != nullptr)
            onStateChanged(this->state);
    }
}
