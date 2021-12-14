#include <gui/containers/musicControlPanel.hpp>

musicControlPanel::musicControlPanel()
    : onPlayClicked(nullptr)
    , onStopClicked(nullptr)
    , onPauseClicked(nullptr)
    , onFastForwardClicked(nullptr)
    , onFastBackwardClicked(nullptr)
    , onPlayNextClicked(nullptr)
    , onPlayPreviousClicked(nullptr) {}


void musicControlPanel::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    musicControlPanel::onPlayClicked = onPlayClicked;
}

void musicControlPanel::setOnStopClicked(const std::function<void()> &onStopClicked) {
    musicControlPanel::onStopClicked = onStopClicked;
}

void musicControlPanel::setOnPauseClicked(const std::function<void()> &onPauseClicked) {
    musicControlPanel::onPauseClicked = onPauseClicked;
}

void musicControlPanel::setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked) {
    musicControlPanel::onFastForwardClicked = onFastForwardClicked;
}

void musicControlPanel::setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked) {
    musicControlPanel::onFastBackwardClicked = onFastBackwardClicked;
}

void musicControlPanel::setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked) {
    musicControlPanel::onPlayNextClicked = onPlayNextClicked;
}

void musicControlPanel::setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked) {
    musicControlPanel::onPlayPreviousClicked = onPlayPreviousClicked;
}


void musicControlPanel::handlePlayClicked() {
    if (onPlayClicked != nullptr) {
        onPlayClicked();
    }
}

void musicControlPanel::handleStopClicked() {
    if (onStopClicked != nullptr) {
        onStopClicked();
    }
}

void musicControlPanel::handlePauseClicked() {
    if (onPauseClicked != nullptr) {
        onPauseClicked();
    }
}

void musicControlPanel::handleFastForwardClicked() {
    if (onFastForwardClicked != nullptr) {
        onFastForwardClicked();
    }
}

void musicControlPanel::handleFastBackwardClicked() {
    if (onFastBackwardClicked != nullptr) {
        onFastBackwardClicked();
    }
}

void musicControlPanel::handlePlayNextClicked() {
    if (onPlayNextClicked != nullptr) {
        onPlayNextClicked();
    }
}

void musicControlPanel::handlePlayPreviousClicked() {
    if (onPlayPreviousClicked != nullptr) {
        onPlayPreviousClicked();
    }
}
