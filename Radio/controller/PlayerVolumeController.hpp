#pragma once
#include <audio/AudioPlayer.hpp>


namespace controller {
    class PlayerVolumeController {
    public:
        explicit PlayerVolumeController(audio::AudioPlayer &audioPlayer);

        void increaseVolume();
        void decreaseVolume();
        void setVolume(std::uint32_t volume);

    private:
        audio::AudioPlayer &audioPlayer;
    };
}


