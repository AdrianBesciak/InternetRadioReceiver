#pragma once
#include <controller/PlayerController.hpp>
#include <audio/AudioPlayer.hpp>
#include <except/ExceptionTranslator.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerRadioController : public PlayerController {
    public:
        PlayerRadioController(except::ExceptionTranslator &exceptionTranslator,
                              audio::AudioPlayer &audioPlayer,
                              model::PlayerModel &playerModel);
    protected:
        std::shared_ptr<io::ReadStream> makeReader(const std::string& source) override;
    };
}


