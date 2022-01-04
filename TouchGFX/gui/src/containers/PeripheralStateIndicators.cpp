#include <gui/containers/PeripheralStateIndicators.hpp>

#include <ApplicationModule.h>

PeripheralStateIndicators::PeripheralStateIndicators() = default;

void PeripheralStateIndicators::initialize() {
    sdMountedInd.setVisible(false);
    sdUnmountedInd.setVisible(true);
    ethernetConnectedInd.setVisible(false);
    ethernetDisconnectedInd.setVisible(true);
}

void PeripheralStateIndicators::setEthernetState(bool state) {
    if (state != ethernetConnectedInd.isVisible()) {
        ethernetConnectedInd.setVisible(state);
        ethernetDisconnectedInd.setVisible(!state);
        ethernetConnectedInd.invalidate();
        ethernetDisconnectedInd.invalidate();
    }
}

void PeripheralStateIndicators::setSdCardState(bool state) {
    if (state != sdMountedInd.isVisible()) {
        sdMountedInd.setVisible(state);
        sdUnmountedInd.setVisible(!state);
        sdMountedInd.invalidate();
        sdUnmountedInd.invalidate();
    }
}

