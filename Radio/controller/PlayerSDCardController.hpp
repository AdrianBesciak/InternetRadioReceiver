#pragma once
#include <audio/AudioPlayer.hpp>
#include <except/ExceptionTranslator.hpp>
#include <model/PlayerModel.hpp>
#include <controller/PlayerController.hpp>

namespace controller {
    class PlayerSDCardController : public PlayerController {
    public:
        PlayerSDCardController(except::ExceptionTranslator &exceptionTranslator,
                               audio::AudioPlayer &audioPlayer,
                               model::PlayerModel &playerModel);

        void playPrevious();
        void playNext();
        void pause();

        void fastForward();
        void fastBackward();

    protected:
        std::shared_ptr<io::ReadStream> makeReader(const std::string &source) override;
    };
}


