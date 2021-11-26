#pragma once
#include <io/watchdog/EthernetWatchdog.hpp>
#include <view/MainDisplay.h>
#include <audio/AudioPlayer.hpp>


class ApplicationModule {
public:
    ApplicationModule();
private:
    io::EthernetWatchdog ethernetWatchdog;
    audio::AudioPlayer audioPlayer;
    view::MainDisplay mainDisplay;
};


