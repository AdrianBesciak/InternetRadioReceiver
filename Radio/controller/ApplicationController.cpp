#include "ApplicationController.hpp"

namespace controller {

    ApplicationController::ApplicationController(audio::AudioPlayer &audioPlayer, model::ApplicationModel &applicationModel)
        : playerRadioController(audioPlayer, applicationModel.getPlayerModel())
        , playerSdCardController(audioPlayer, applicationModel.getPlayerModel())
        , playerVolumeController(audioPlayer)
        , errorController(applicationModel.getErrorModel()) {}

    PlayerRadioController &ApplicationController::getPlayerRadioController() {
        return playerRadioController;
    }

    PlayerSDCardController &ApplicationController::getPlayerSdCardController() {
        return playerSdCardController;
    }

    PlayerVolumeController &ApplicationController::getPlayerVolumeController() {
        return playerVolumeController;
    }

    ErrorController &ApplicationController::getErrorController() {
        return errorController;
    }
}
