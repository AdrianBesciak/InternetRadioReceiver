#include <gui/containers/ControlPanelSD.hpp>

ControlPanelSD::ControlPanelSD()
    : onPlayClicked(nullptr)
    , onStopClicked(nullptr)
    , onPauseClicked(nullptr)
    , onFastForwardClicked(nullptr)
    , onFastBackwardClicked(nullptr)
    , onPlayNextClicked(nullptr)
    , onPlayPreviousClicked(nullptr) {}


void ControlPanelSD::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    ControlPanelSD::onPlayClicked = onPlayClicked;
}

void ControlPanelSD::setOnStopClicked(const std::function<void()> &onStopClicked) {
    ControlPanelSD::onStopClicked = onStopClicked;
}

void ControlPanelSD::setOnPauseClicked(const std::function<void()> &onPauseClicked) {
    ControlPanelSD::onPauseClicked = onPauseClicked;
}

void ControlPanelSD::setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked) {
    ControlPanelSD::onFastForwardClicked = onFastForwardClicked;
}

void ControlPanelSD::setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked) {
    ControlPanelSD::onFastBackwardClicked = onFastBackwardClicked;
}

void ControlPanelSD::setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked) {
    ControlPanelSD::onPlayNextClicked = onPlayNextClicked;
}

void ControlPanelSD::setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked) {
    ControlPanelSD::onPlayPreviousClicked = onPlayPreviousClicked;
}


void ControlPanelSD::setPlayVisible(bool visible) {
    if (visible != playButton.isVisible()) {
        playButton.setVisible(visible);
        playButton.invalidate();
    }
}

void ControlPanelSD::setPauseVisible(bool visible) {
    if (visible != pauseButton.isVisible()) {
        pauseButton.setVisible(visible);
        pauseButton.invalidate();
    }
}


void ControlPanelSD::handlePlayClicked() {
    if (onPlayClicked != nullptr) {
        onPlayClicked();
    }
}

void ControlPanelSD::handleStopClicked() {
    if (onStopClicked != nullptr) {
        onStopClicked();
    }
}

void ControlPanelSD::handlePauseClicked() {
    if (onPauseClicked != nullptr) {
        onPauseClicked();
    }
}

void ControlPanelSD::handleFastForwardClicked() {
    if (onFastForwardClicked != nullptr) {
        onFastForwardClicked();
    }
}

void ControlPanelSD::handleFastBackwardClicked() {
    if (onFastBackwardClicked != nullptr) {
        onFastBackwardClicked();
    }
}

void ControlPanelSD::handlePlayNextClicked() {
    if (onPlayNextClicked != nullptr) {
        onPlayNextClicked();
    }
}

void ControlPanelSD::handlePlayPreviousClicked() {
    if (onPlayPreviousClicked != nullptr) {
        onPlayPreviousClicked();
    }
}
