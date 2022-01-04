#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/ApplicationModel.hpp>
#include <controller/VolumeController.hpp>

namespace controller {
    class ApplicationController {
    public:
        ApplicationController(audio::AudioPlayer &audioPlayer, model::ApplicationModel &applicationModel);
        VolumeController &getVolumeController();

        void playRadio();
        void playSDCard();
        void stop();
        void pause();

        void playPrevious();
        void playNext();

        void fastForward();
        void fastBackward();

        void playFromRadio(std::size_t idx);
        void playFromSDCard(std::size_t idx);
    private:
        VolumeController volumeController;

        audio::AudioPlayer &audioPlayer;
        model::ApplicationModel &applicationModel;
    };
}
