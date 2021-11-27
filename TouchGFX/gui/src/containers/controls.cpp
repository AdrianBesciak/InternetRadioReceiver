#include <gui/containers/controls.hpp>

#include <ApplicationModule.h>

#include <iostream>

controls::controls()
{
}

void controls::initialize()
{
    controlsBase::initialize();

    //ApplicationModule* inst = ApplicationModule::getInstance();
    //inst->setStateIndicators(this);
    sdMountedInd.setVisible(false);
    sdUnmountedInd.setVisible(false);
    ethernetConnectedInd.setVisible(false);
    ethernetDisconnectedInd.setVisible(false);
}

void controls::ethernetStateChanged(bool connected)
{
    if (applicationModuleInstance)
    {
        ethernetConnectedInd.setVisible(connected);
        ethernetDisconnectedInd.setVisible(not connected);
    }

}

void controls::sdCardStateChanged(bool mounted)
{
    if (applicationModuleInstance)
    {
        sdMountedInd.setVisible(mounted);
        sdUnmountedInd.setVisible(not mounted);
    }

}