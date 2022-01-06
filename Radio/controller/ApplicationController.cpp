#include "ApplicationController.hpp"

namespace controller {

    ApplicationController::ApplicationController(except::ExceptionTranslator &exceptionTranslator,
                                                 audio::AudioPlayer &audioPlayer,
                                                 model::ApplicationModel &applicationModel)
        : playerRadioController(exceptionTranslator, audioPlayer, applicationModel.getPlayerModel())
        , playerSdCardController(exceptionTranslator, audioPlayer, applicationModel.getPlayerModel())
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
