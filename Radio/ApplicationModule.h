#pragma once
#include <io/watchdog/EthernetWatchdog.hpp>
#include <io/watchdog/SDCardWatchdog.hpp>
#include <model/ApplicationModel.hpp>
#include <view/MainDisplay.h>
#include <audio/AudioPlayer.hpp>

class ApplicationModule {
public:
    ApplicationModule();
    [[nodiscard]] const model::ApplicationModel &getApplicationModel() const;
    static ApplicationModule& getInstance();
private:
    static ApplicationModule *instance;

    void bindWatchdogs();
    void bindPlayerState();
    void startTasks();

    io::EthernetWatchdog ethernetWatchdog;
    io::SDCardWatchdog sdCardWatchdog;
    audio::AudioPlayer audioPlayer;
    view::MainDisplay mainDisplay;
    model::ApplicationModel applicationModel;
};

extern ApplicationModule* applicationModuleInstance;
