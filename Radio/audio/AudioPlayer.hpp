#pragma once
#include <functional>
#include <memory>
#include <string>
#include <audio/reader/AudioReader.hpp>
#include <sys/task/DelayTask.hpp>
#include <sys/Mutex.h>

namespace audio {
    class AudioPlayer : public sys::DelayTask {
        friend class Handlers;
    public:
        enum class State {
            NO_SOURCE,
            STOPPED,
            PLAYING,
            PAUSED
        };

        AudioPlayer();
        ~AudioPlayer() override;
        void setSource(const std::shared_ptr<AudioReader> &reader);
        void unloadSource();
        void play();
        void pause();
        void stop();
        void seek(float time);

        [[nodiscard]] std::string getSource() const;

        [[nodiscard]] unsigned getVolume() const;
        void setVolume(unsigned volume);

        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] bool isPlaying() const;
        [[nodiscard]] bool isPaused() const;
        [[nodiscard]] bool isStopped() const;
        [[nodiscard]] State getState() const;

        [[nodiscard]] float getCurrentTime() const;
        [[nodiscard]] float getEndTime() const;

        void setOnStateChanged(const std::function<void(State)>& onStateChanged);
        void setOnProgressChanged(const std::function<void(float,float)>& onProgressChanged);
        void setOnMediumChanged(const std::function<void(const std::string&)>& onMediumChanged);
        void setOnVolumeChanged(const std::function<void(unsigned)>& onVolumeChanged);
        void setOnFinished(const std::function<void()> &onFinished);
        void setOnError(const std::function<void(const std::exception &)> &onError);

    private:
        enum class BufferState {
            None,
            Started,
            HalfWayThrough,
            Done,
            Error
        };

        void executeIteration() override;
        void updateState(State state);

        void playerInitialize();
        void playerSetFrequency();
        void playerStop();
        void playerPlayBuffer();
        void playerSetVolume();
        void playerPause();
        void playerUnpause();

        void handleError();
        void handleBufferHalfWay();
        void handleBufferDone();

        void validateNotEmpty() const;

        void clearLeftPartBuffer();
        void clearRightPartBuffer();
        void clearBuffer();

        State state;
        BufferState bufferState;
        unsigned volume;
        std::shared_ptr<AudioReader> reader;
        std::vector<std::int16_t> playingBuffer;

        std::function<void(State)> onStateChanged;
        std::function<void(float,float)> onProgressChanged;
        std::function<void(const std::string&)> onMediumChanged;
        std::function<void(unsigned)> onVolumeChanged;
        std::function<void()> onFinished;
        std::function<void(const std::exception&)> onError;

        sys::Mutex readerMutex;

        static AudioPlayer* instance;
    };
}
