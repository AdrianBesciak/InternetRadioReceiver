#include <gui/containers/delegate/ControlPanelSDDelegate.hpp>

ControlPanelSDDelegate::~ControlPanelSDDelegate() = default;

void ControlPanelSDDelegate::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    getControlPanel().setOnPlayClicked(onPlayClicked);
}

void ControlPanelSDDelegate::setOnStopClicked(const std::function<void()> &onStopClicked) {
    getControlPanel().setOnStopClicked(onStopClicked);
}

void ControlPanelSDDelegate::setOnPauseClicked(const std::function<void()> &onPauseClicked) {
    getControlPanel().setOnPauseClicked(onPauseClicked);
}

void ControlPanelSDDelegate::setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked) {
    getControlPanel().setOnFastForwardClicked(onFastForwardClicked);
}

void ControlPanelSDDelegate::setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked) {
    getControlPanel().setOnFastBackwardClicked(onFastBackwardClicked);
}

void ControlPanelSDDelegate::setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked) {
    getControlPanel().setOnPlayNextClicked(onPlayNextClicked);
}

void ControlPanelSDDelegate::setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked) {
    getControlPanel().setOnPlayPreviousClicked(onPlayPreviousClicked);
}

void ControlPanelSDDelegate::setPlayVisible(bool visible) {
    getControlPanel().setPlayVisible(visible);
}

void ControlPanelSDDelegate::setPauseVisible(bool visible) {
    getControlPanel().setPauseVisible(visible);
}
