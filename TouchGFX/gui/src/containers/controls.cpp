#include <gui/containers/controls.hpp>

#include <ApplicationModule.h>

controls::controls()
{
    Application::getInstance()->registerTimerWidget(this);
}

controls::~controls() {
    Application::getInstance()->unregisterTimerWidget(this);
}

void controls::initialize()
{
    controlsBase::initialize();

    sdMountedInd.setVisible(previousSdCardState);
    sdUnmountedInd.setVisible(not previousSdCardState);
    ethernetConnectedInd.setVisible(previousEthernetState);
    ethernetDisconnectedInd.setVisible(not previousEthernetState);
}

void controls::handleTickEvent()
{
    bool invalidate{false};

    if (previousSdCardState != applicationModuleInstance->getSdCardState()) {
        sdMountedInd.setVisible(applicationModuleInstance->getSdCardState());
        sdUnmountedInd.setVisible(not applicationModuleInstance->getSdCardState());
        previousSdCardState = applicationModuleInstance->getSdCardState();
        invalidate = true;
    }
    if (previousEthernetState != applicationModuleInstance->getEthernetState()) {
        ethernetConnectedInd.setVisible(applicationModuleInstance->getEthernetState());
        ethernetDisconnectedInd.setVisible(not applicationModuleInstance->getEthernetState());
        previousEthernetState = applicationModuleInstance->getEthernetState();
        invalidate = true;
    }

    if (invalidate) {
        this->invalidate();
    }
}