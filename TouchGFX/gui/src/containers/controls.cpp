#include <gui/containers/controls.hpp>

#include <ApplicationModule.h>

controls::controls()
    : ethernetStateDirty(false)
    , sdCardStateDirty(false) {
    Application::getInstance()->registerTimerWidget(this);
}

controls::~controls() {
    Application::getInstance()->unregisterTimerWidget(this);
}

void controls::initialize() {
    controlsBase::initialize();
    sdMountedInd.setVisible(false);
    sdUnmountedInd.setVisible(true);
    ethernetConnectedInd.setVisible(false);
    ethernetDisconnectedInd.setVisible(true);
}

void controls::setEthernetState(bool state) {
    if (state != ethernetConnectedInd.isVisible()) {
        ethernetConnectedInd.setVisible(state);
        ethernetDisconnectedInd.setVisible(!state);
        ethernetStateDirty = true;
    }
}

void controls::setSdCardState(bool state) {
    if (state != sdMountedInd.isVisible()) {
        sdMountedInd.setVisible(state);
        sdUnmountedInd.setVisible(!state);
        sdCardStateDirty = true;
    }
}

void controls::handleTickEvent() {
    if (ethernetStateDirty) {
        ethernetConnectedInd.invalidate();
        ethernetDisconnectedInd.invalidate();
        ethernetStateDirty = false;
    }
    if (sdCardStateDirty) {
        sdMountedInd.invalidate();
        sdUnmountedInd.invalidate();
        sdCardStateDirty = false;
    }
}
