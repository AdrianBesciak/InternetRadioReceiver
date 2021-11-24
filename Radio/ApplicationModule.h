#pragma once
#include <view/MainDisplay.h>
#include <audio/AudioPlayer.hpp>


class ApplicationModule {
public:
    ApplicationModule();
private:
    audio::AudioPlayer audioPlayer;
    view::MainDisplay mainDisplay;
};


