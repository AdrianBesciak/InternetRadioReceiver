#include <gui/containers/ControlPanelRadio.hpp>

ControlPanelRadio::ControlPanelRadio()
    : onPlayClicked(nullptr)
    , onStopClicked(nullptr) {}


void ControlPanelRadio::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    ControlPanelRadio::onPlayClicked = onPlayClicked;
}

void ControlPanelRadio::setOnStopClicked(const std::function<void()> &onStopClicked) {
    ControlPanelRadio::onStopClicked = onStopClicked;
}


void ControlPanelRadio::setPlayVisible(bool visible) {
    if (playButton.isVisible() != visible) {
        playButton.setVisible(visible);
        playButton.invalidate();
    }
}

void ControlPanelRadio::setStopVisible(bool visible) {
    if (stopButton.isVisible() != visible) {
        stopButton.setVisible(visible);
        stopButton.invalidate();
    }
}


void ControlPanelRadio::handlePlayClicked() {
    if (onPlayClicked != nullptr) {
        onPlayClicked();
    }
}

void ControlPanelRadio::handleStopClicked() {
    if (onStopClicked != nullptr) {
        onStopClicked();
    }
}
