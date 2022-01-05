#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/ApplicationModel.hpp>
#include <controller/VolumeController.hpp>
#include <controller/ErrorController.hpp>

namespace controller {
    class ApplicationController {
    public:
        ApplicationController(audio::AudioPlayer &audioPlayer, model::ApplicationModel &applicationModel);
        VolumeController &getVolumeController();
        ErrorController &getErrorController();

        void stop();
        void pause();

        void playPrevious();
        void playNext();

        void fastForward();
        void fastBackward();

        void playFromRadio(std::size_t idx);
        void playFromSDCard(std::size_t idx);
        void playFromRadio();
        void playFromSDCard();
    private:
        VolumeController volumeController;
        ErrorController errorController;

        audio::AudioPlayer &audioPlayer;
        model::ApplicationModel &applicationModel;
    };
}
