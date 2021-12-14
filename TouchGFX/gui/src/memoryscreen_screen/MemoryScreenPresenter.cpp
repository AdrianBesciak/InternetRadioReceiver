#include <gui/memoryscreen_screen/MemoryScreenView.hpp>
#include <gui/memoryscreen_screen/MemoryScreenPresenter.hpp>

MemoryScreenPresenter::MemoryScreenPresenter(MemoryScreenView& view)
    : view(view) {}

void MemoryScreenPresenter::activate() {
    view.setOnPlayClicked([&]{applicationController->playSDCard();});
    view.setOnStopClicked([&]{applicationController->stop();});
    view.setOnPauseClicked([&]{applicationController->pause();});
    view.setOnFastForwardClicked([&]{applicationController->fastForward();});
    view.setOnFastBackwardClicked([&]{applicationController->fastBackward();});
    view.setOnPlayNextClicked([&]{applicationController->playNext();});
    view.setOnPlayPreviousClicked([&]{applicationController->playPrevious();});
}

void MemoryScreenPresenter::deactivate() {
    view.setOnPlayClicked(nullptr);
    view.setOnStopClicked(nullptr);
    view.setOnPauseClicked(nullptr);
    view.setOnFastForwardClicked(nullptr);
    view.setOnFastBackwardClicked(nullptr);
    view.setOnPlayNextClicked(nullptr);
    view.setOnPlayPreviousClicked(nullptr);
}

void MemoryScreenPresenter::update() {
    updatePeripheralsState([&](auto... states) {view.setPeripheralState(states...);});
}
