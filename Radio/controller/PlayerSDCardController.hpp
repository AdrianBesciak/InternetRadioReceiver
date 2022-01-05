#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerSDCardController {
    public:
        PlayerSDCardController(audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel);

        void play();
        void playFromPlaylist(std::size_t idx);
        void playPrevious();
        void playNext();
        void pause();
        void stop();

        void fastForward();
        void fastBackward();

    private:
        audio::AudioPlayer& audioPlayer;
        model::PlayerModel& playerModel;
    };
}


