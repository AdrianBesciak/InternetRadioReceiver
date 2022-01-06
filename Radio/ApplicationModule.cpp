#include "ApplicationModule.h"
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
    , radioPlaylist()
    , sdCardPlaylist()
    , mainDisplay()
    , applicationModel(radioPlaylist, sdCardPlaylist)
    , applicationController(audioPlayer, applicationModel) {
    if (instance != nullptr) {
        throw sys::SingleInstanceException("ApplicationModule instance already exists");
    }
    instance = this;
    bindWatchdogs();
    bindPlayerState();
    startTasks();
}


const model::ApplicationModel &ApplicationModule::getApplicationModel() const {
    return applicationModel;
}

controller::ApplicationController &ApplicationModule::getApplicationController() {
    return applicationController;
}

const controller::ApplicationController &ApplicationModule::getApplicationController() const {
    return applicationController;
}


void ApplicationModule::bindWatchdogs() {
    model::PeripheralStateModel &model = applicationModel.getPeripheralStateModel();
    ethernetWatchdog.setOnStateChanged([&](bool state) {
        model.setEthernetState(state);
        radioPlaylist.update();
    });
    sdCardWatchdog.setOnStateChanged([&](bool state) {
        model.setSdCardState(state);
        sdCardPlaylist.update();
    });
}

void ApplicationModule::bindPlayerState() {
    model::PlayerModel &playerModel = applicationModel.getPlayerModel();
    audioPlayer.setOnStateChanged([&](audio::AudioPlayer::State state) { playerModel.setState(state);});
    audioPlayer.setOnVolumeChanged([&](unsigned volume) { playerModel.setVolume(volume);});
    audioPlayer.setOnProgressChanged([&](float current, float total) {
        playerModel.setProgress(current, total);
        if (std::abs(current - total) <= 0.001 && total != 0.0f) {
            applicationController.getPlayerSdCardController().playNext();
        }
    });
}

void ApplicationModule::startTasks() {
    ethernetWatchdog.startTask(sys::TaskPriority::LOW);
    sdCardWatchdog.startTask(sys::TaskPriority::LOW);
    audioPlayer.startTask(sys::TaskPriority::REALTIME);
    mainDisplay.startTask(sys::TaskPriority::LOW);
}
