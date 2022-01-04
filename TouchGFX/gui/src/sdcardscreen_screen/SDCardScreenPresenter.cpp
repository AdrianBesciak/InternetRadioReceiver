#include <gui/sdcardscreen_screen/SDCardScreenPresenter.hpp>
#include <gui/sdcardscreen_screen/SDCardScreenView.hpp>

SDCardScreenPresenter::SDCardScreenPresenter(SDCardScreenView& view)
    : view(view) {}

void SDCardScreenPresenter::activate() {
    view.setOnVolumePlusClicked([&] { applicationController->increaseVolume();});
    view.setOnVolumeMinusClicked([&] { applicationController->decreaseVolume();});

    view.setOnPlayClicked([&]{applicationController->playSDCard();});
    view.setOnStopClicked([&]{applicationController->stop();});
    view.setOnPauseClicked([&]{applicationController->pause();});
    view.setOnFastForwardClicked([&]{applicationController->fastForward();});
    view.setOnFastBackwardClicked([&]{applicationController->fastBackward();});
    view.setOnPlayNextClicked([&]{applicationController->playNext();});
    view.setOnPlayPreviousClicked([&]{applicationController->playPrevious();});
}

void SDCardScreenPresenter::deactivate() {
    view.setOnVolumePlusClicked(nullptr);
    view.setOnVolumeMinusClicked(nullptr);

    view.setOnPlayClicked(nullptr);
    view.setOnStopClicked(nullptr);
    view.setOnPauseClicked(nullptr);
    view.setOnFastForwardClicked(nullptr);
    view.setOnFastBackwardClicked(nullptr);
    view.setOnPlayNextClicked(nullptr);
    view.setOnPlayPreviousClicked(nullptr);
}

void SDCardScreenPresenter::update() {
    updatePeripheralsState([&](auto... states) {view.setPeripheralState(states...);});
}
