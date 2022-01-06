#pragma once
#include <except/ExceptionTranslator.hpp>
#include <io/watchdog/EthernetWatchdog.hpp>
#include <io/watchdog/SDCardWatchdog.hpp>
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

    void bindErrors();
    void bindWatchdogs();
    void bindPlayerState();
    void startTasks();

    except::ExceptionTranslator exceptionTranslator;

    io::EthernetWatchdog ethernetWatchdog;
    io::SDCardWatchdog sdCardWatchdog;

    audio::AudioPlayer audioPlayer;
    audio::RadioPlaylist radioPlaylist;
    audio::SDCardPlaylist sdCardPlaylist;

    view::MainDisplay mainDisplay;

    model::ApplicationModel applicationModel;
    controller::ApplicationController applicationController;
};

extern ApplicationModule* applicationModuleInstance;
