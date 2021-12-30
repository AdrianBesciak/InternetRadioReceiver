#include "ApplicationController.hpp"

namespace controller {

    ApplicationController::ApplicationController(audio::AudioPlayer &audioPlayer,
                                                 model::ApplicationModel &applicationModel)
        : audioPlayer(audioPlayer)
        , applicationModel(applicationModel) {}

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

    void ApplicationController::increaseVolume() {

    }

    void ApplicationController::decreaseVolume() {

    }

    void ApplicationController::setVolume(std::uint32_t volume) {
        audioPlayer.setVolume(volume);
    }

    void ApplicationController::playFromRadio(std::size_t idx) {

    }

    void ApplicationController::playFromSDCard(std::size_t idx) {

    }
}
