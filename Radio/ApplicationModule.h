#pragma once
#include <io/watchdog/EthernetWatchdog.hpp>
#include <io/watchdog/SDCardWatchdog.hpp>
#include <audio/AudioPlayer.hpp>
#include <view/MainDisplay.h>

#include <controller/ApplicationController.hpp>
#include <model/ApplicationModel.hpp>

class ApplicationModule {
public:
    ApplicationModule();
    [[nodiscard]] const model::ApplicationModel &getApplicationModel() const;

    controller::ApplicationController &getApplicationController();
    [[nodiscard]] const controller::ApplicationController &getApplicationController() const;

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
    controller::ApplicationController applicationController;
};

extern ApplicationModule* applicationModuleInstance;
