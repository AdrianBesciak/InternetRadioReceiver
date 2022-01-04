#pragma once
#include <audio/AudioPlayer.hpp>


namespace controller {
    class VolumeController {
    public:
        explicit VolumeController(audio::AudioPlayer &audioPlayer);

        void increaseVolume();
        void decreaseVolume();
        void setVolume(std::uint32_t volume);

    private:
        audio::AudioPlayer &audioPlayer;
    };
}


