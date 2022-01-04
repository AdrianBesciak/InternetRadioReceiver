#include <gui/containers/delegate/ControlPanelRadioDelegate.hpp>

ControlPanelRadioDelegate::~ControlPanelRadioDelegate() = default;

void ControlPanelRadioDelegate::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    getControlPanel().setOnPlayClicked(onPlayClicked);
}

void ControlPanelRadioDelegate::setOnStopClicked(const std::function<void()> &onStopClicked) {
    getControlPanel().setOnStopClicked(onStopClicked);
}

void ControlPanelRadioDelegate::setPlayVisible(bool visible) {
    getControlPanel().setPlayVisible(visible);
}

void ControlPanelRadioDelegate::setStopVisible(bool visible) {
    getControlPanel().setStopVisible(visible);
}
