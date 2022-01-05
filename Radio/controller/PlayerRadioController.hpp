#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerRadioController {
    public:
        PlayerRadioController(audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel);

        void play();
        void playFromPlaylist(std::size_t idx);
        void stop();

    private:
        audio::AudioPlayer& audioPlayer;
        model::PlayerModel& playerModel;
    };
}


