#include <gui/containers/controls.hpp>

#include <ApplicationModule.h>

controls::controls() = default;

void controls::initialize() {
    sdMountedInd.setVisible(false);
    sdUnmountedInd.setVisible(true);
    ethernetConnectedInd.setVisible(false);
    ethernetDisconnectedInd.setVisible(true);
}

void controls::setEthernetState(bool state) {
    if (state != ethernetConnectedInd.isVisible()) {
        ethernetConnectedInd.setVisible(state);
        ethernetDisconnectedInd.setVisible(!state);
        ethernetConnectedInd.invalidate();
        ethernetDisconnectedInd.invalidate();
    }
}

void controls::setSdCardState(bool state) {
    if (state != sdMountedInd.isVisible()) {
        sdMountedInd.setVisible(state);
        sdUnmountedInd.setVisible(!state);
        sdMountedInd.invalidate();
        sdUnmountedInd.invalidate();
    }
}

