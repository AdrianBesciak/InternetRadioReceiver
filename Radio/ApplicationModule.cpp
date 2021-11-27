#include "ApplicationModule.h"
#include <iostream>
#include <io/stream/network/HttpStream.hpp>
#include <io/stream/file/FileReadStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>
#include <filesystem/DirectoryListing.hpp>
#include <sys/except/SingleInstanceException.hpp>

ApplicationModule *ApplicationModule::instance = nullptr;

ApplicationModule &ApplicationModule::getInstance() {
    if (instance == nullptr) {
        throw std::logic_error("ApplicationModule not initialized yet");
    }
    return *instance;
}

ApplicationModule::ApplicationModule()
    : ethernetWatchdog()
    , sdCardWatchdog()
    , audioPlayer()
    , mainDisplay()
    , applicationModel() {
    if (instance != nullptr) {
        throw sys::SingleInstanceException("AudioPlayer instance already exists");
    }
    instance = this;
    bindStateObservers();
    startTasks();
}

void ApplicationModule::bindStateObservers() {
    model::PeripheralStateModel &model = applicationModel.getPeripheralStateModel();
    ethernetWatchdog.setOnStateChanged([&](bool state) {model.setEthernetState(state);});
    sdCardWatchdog.setOnStateChanged([&](bool state) {model.setSdCardState(state);});
}

void ApplicationModule::startTasks() {
    ethernetWatchdog.startTask(sys::TaskPriority::LOW);
    sdCardWatchdog.startTask(sys::TaskPriority::LOW);
    audioPlayer.startTask(sys::TaskPriority::REALTIME);
    mainDisplay.startTask(sys::TaskPriority::LOW);
}

const model::ApplicationModel &ApplicationModule::getApplicationModel() const {
    return applicationModel;
}
