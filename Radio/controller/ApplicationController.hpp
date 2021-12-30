#pragma once
#include <audio/AudioPlayer.hpp>
#include <model/ApplicationModel.hpp>

namespace controller {
    class ApplicationController {
    public:
        ApplicationController(audio::AudioPlayer &audioPlayer, model::ApplicationModel &applicationModel);
        void playRadio();
        void playSDCard();
        void stop();
        void pause();

        void playPrevious();
        void playNext();

        void fastForward();
        void fastBackward();

        void increaseVolume();
        void decreaseVolume();
        void setVolume(std::uint32_t volume);

        void playFromRadio(std::size_t idx);
        void playFromSDCard(std::size_t idx);
    private:
        audio::AudioPlayer &audioPlayer;
        model::ApplicationModel &applicationModel;
    };
}
