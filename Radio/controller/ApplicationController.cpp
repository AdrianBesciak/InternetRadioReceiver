#include "ApplicationController.hpp"

namespace controller {

    ApplicationController::ApplicationController(audio::AudioPlayer &audioPlayer,
                                                 model::ApplicationModel &applicationModel)
        : volumeController(audioPlayer)
        , audioPlayer(audioPlayer)
        , applicationModel(applicationModel) {}

    VolumeController &ApplicationController::getVolumeController() {
        return volumeController;
    }


    void ApplicationController::playRadio() {

    }

    void ApplicationController::playSDCard() {

    }

    void ApplicationController::stop() {

    }

    void ApplicationController::pause() {

    }

    void ApplicationController::playPrevious() {

    }

    void ApplicationController::playNext() {

    }

    void ApplicationController::fastForward() {

    }

    void ApplicationController::fastBackward() {

    }

    void ApplicationController::playFromRadio(std::size_t idx) {

    }

    void ApplicationController::playFromSDCard(std::size_t idx) {

    }
}
