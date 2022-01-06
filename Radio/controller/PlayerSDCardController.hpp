#pragma once
#include <audio/AudioPlayer.hpp>
#include <except/ExceptionTranslator.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerSDCardController {
    public:
        PlayerSDCardController(except::ExceptionTranslator &exceptionTranslator, audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel);

        void play();
        void playFromPlaylist(std::size_t idx);
        void playPrevious();
        void playNext();
        void pause();
        void stop();

        void fastForward();
        void fastBackward();

    private:
        except::ExceptionTranslator& exceptionTranslator;
        audio::AudioPlayer& audioPlayer;
        model::PlayerModel& playerModel;
    };
}


