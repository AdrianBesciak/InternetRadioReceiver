#include <gui/containers/radioControlPanel.hpp>

radioControlPanel::radioControlPanel()
    : onPlayClicked(nullptr)
    , onStopClicked(nullptr) {}

void radioControlPanel::setPlayVisible(bool visible) {
    if (play.isVisible() != visible) {
        play.setVisible(visible);
        play.invalidate();
    }
}

void radioControlPanel::setStopVisible(bool visible) {
    if (stop.isVisible() != visible) {
        stop.setVisible(visible);
        stop.invalidate();
    }
}

void radioControlPanel::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    radioControlPanel::onPlayClicked = onPlayClicked;
}

void radioControlPanel::setOnStopClicked(const std::function<void()> &onStopClicked) {
    radioControlPanel::onStopClicked = onStopClicked;
}

void radioControlPanel::handlePlayClicked() {
    if (onPlayClicked != nullptr) {
        onPlayClicked();
    }
}

void radioControlPanel::handleStopClicked() {
    if (onStopClicked != nullptr) {
        onStopClicked();
    }
}
