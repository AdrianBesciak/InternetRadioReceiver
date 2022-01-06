#pragma once
#include <audio/AudioPlayer.hpp>
#include <except/ExceptionTranslator.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerRadioController {
    public:
        PlayerRadioController(except::ExceptionTranslator &exceptionTranslator, audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel);

        void play();
        void playFromPlaylist(std::size_t idx);
        void stop();

    private:
        except::ExceptionTranslator& exceptionTranslator;
        audio::AudioPlayer& audioPlayer;
        model::PlayerModel& playerModel;
    };
}


