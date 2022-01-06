#include "ApplicationModule.h"
#include <sys/except/SingleInstanceException.hpp>


ApplicationModule *ApplicationModule::instance = nullptr;

ApplicationModule &ApplicationModule::getInstance() {
    if (instance == nullptr) {
        throw std::logic_error("ApplicationModule not initialized yet");
    }
    return *instance;
}


ApplicationModule::ApplicationModule()
    : exceptionTranslator()
    , ethernetWatchdog()
    , sdCardWatchdog()
    , audioPlayer()
    , radioPlaylist()
    , sdCardPlaylist()
    , mainDisplay()
    , applicationModel(radioPlaylist, sdCardPlaylist)
    , applicationController(exceptionTranslator, audioPlayer, applicationModel) {
    if (instance != nullptr) {
        throw sys::SingleInstanceException("ApplicationModule instance already exists");
    }
    instance = this;
    bindErrors();
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


void ApplicationModule::bindErrors() {
    exceptionTranslator.setOnErrorMessage([&](auto &message) { applicationModel.getErrorModel().setErrorMessage(message); });
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
    audioPlayer.setOnProgressChanged([&](float current, float total) {playerModel.setProgress(current, total);});
    audioPlayer.setOnVolumeChanged([&](unsigned volume) { playerModel.setVolume(volume);});
    audioPlayer.setOnFinished([&] { applicationController.getPlayerSdCardController().playNext(); });
    audioPlayer.setOnError([&](auto &exc) { exceptionTranslator.translate(exc); });
}

void ApplicationModule::startTasks() {
    ethernetWatchdog.startTask(sys::TaskPriority::LOW);
    sdCardWatchdog.startTask(sys::TaskPriority::LOW);
    audioPlayer.startTask(sys::TaskPriority::REALTIME);
    mainDisplay.startTask(sys::TaskPriority::LOW);
}
