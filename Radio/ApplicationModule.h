#pragma once
#include <io/watchdog/EthernetWatchdog.hpp>
#include <io/watchdog/SDCardWatchdog.hpp>
#include <view/MainDisplay.h>
#include <audio/AudioPlayer.hpp>

//#include <gui/containers/controls.hpp>

class ApplicationModule {
public:
    ApplicationModule();

    //void setStateIndicators(controls* indicators);
    //static ApplicationModule* getInstance(){return instance;}

    bool getEthernetState();
    bool getSdCardState();
private:
    io::EthernetWatchdog ethernetWatchdog;
    io::SDCardWatchdog sdCardWatchdog;
    audio::AudioPlayer audioPlayer;
    view::MainDisplay mainDisplay;

    //controls* stateIndicators;

};

extern ApplicationModule* applicationModuleInstance;
