#pragma once
#include <io/watchdog/EthernetWatchdog.hpp>
#include <io/watchdog/SDCardWatchdog.hpp>
#include <view/MainDisplay.h>
#include <audio/AudioPlayer.hpp>


class ApplicationModule {
public:
    ApplicationModule();
private:
    io::EthernetWatchdog ethernetWatchdog;
    io::SDCardWatchdog sdCardWatchdog;
    audio::AudioPlayer audioPlayer;
    view::MainDisplay mainDisplay;
};


