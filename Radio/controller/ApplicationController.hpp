#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/ApplicationModel.hpp>
#include <controller/PlayerRadioController.hpp>
#include <controller/PlayerSDCardController.hpp>
#include <controller/PlayerVolumeController.hpp>
#include <controller/ErrorController.hpp>

namespace controller {
    class ApplicationController {
    public:
        ApplicationController(audio::AudioPlayer &audioPlayer, model::ApplicationModel &applicationModel);
        PlayerRadioController &getPlayerRadioController();
        PlayerSDCardController &getPlayerSdCardController();
        PlayerVolumeController &getPlayerVolumeController();
        ErrorController &getErrorController();

    private:
        PlayerRadioController playerRadioController;
        PlayerSDCardController playerSdCardController;
        PlayerVolumeController playerVolumeController;
        ErrorController errorController;
    };
}
