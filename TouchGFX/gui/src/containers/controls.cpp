#include <gui/containers/controls.hpp>

#include <ApplicationModule.h>

controls::controls()
{
}

void controls::initialize()
{
    controlsBase::initialize();

    sdMountedInd.setVisible(false);
    sdUnmountedInd.setVisible(false);
    ethernetConnectedInd.setVisible(false);
    ethernetDisconnectedInd.setVisible(false);
}

void controls::ethernetStateChanged(bool connected)
{
    ethernetConnectedInd.setVisible(connected);
    ethernetDisconnectedInd.setVisible(not connected);
}

void controls::sdCardStateChanged(bool mounted)
{
    sdMountedInd.setVisible(mounted);
    sdUnmountedInd.setVisible(not mounted);
}