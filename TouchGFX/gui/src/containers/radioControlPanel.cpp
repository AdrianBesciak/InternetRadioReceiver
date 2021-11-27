#include <gui/containers/radioControlPanel.hpp>

radioControlPanel::radioControlPanel()
    : playDirty(false)
    , stopDirty(false) {
    Application::getInstance()->registerTimerWidget(this);
}

radioControlPanel::~radioControlPanel() {
    Application::getInstance()->unregisterTimerWidget(this);
}

void radioControlPanel::setPlayVisible(bool visible) {
    if (play.isVisible() != visible) {
        play.setVisible(visible);
        playDirty = true;
    }
}

void radioControlPanel::setStopVisible(bool visible) {
    if (stop.isVisible() != visible) {
        stop.setVisible(visible);
        stopDirty = true;
    }
}

void radioControlPanel::handleTickEvent() {
    if (playDirty) {
        play.invalidate();
        playDirty = false;
    }
    if (stopDirty) {
        stop.invalidate();
        stopDirty = false;
    }
}

