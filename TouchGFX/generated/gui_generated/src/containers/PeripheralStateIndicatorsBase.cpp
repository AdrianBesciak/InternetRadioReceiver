/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/PeripheralStateIndicatorsBase.hpp>
#include <BitmapDatabase.hpp>

PeripheralStateIndicatorsBase::PeripheralStateIndicatorsBase()
{
    setWidth(100);
    setHeight(50);
    sdUnmountedInd.setXY(0, 0);
    sdUnmountedInd.setBitmap(touchgfx::Bitmap(BITMAP_SDCARDUNMOUNTEDIND_ID));

    sdMountedInd.setXY(0, 0);
    sdMountedInd.setVisible(false);
    sdMountedInd.setBitmap(touchgfx::Bitmap(BITMAP_SDCARDMOUNTEDIND_ID));

    ethernetConnectedInd.setXY(50, 0);
    ethernetConnectedInd.setVisible(false);
    ethernetConnectedInd.setBitmap(touchgfx::Bitmap(BITMAP_LAN_ON_IND_ID));

    ethernetDisconnectedInd.setXY(50, 0);
    ethernetDisconnectedInd.setBitmap(touchgfx::Bitmap(BITMAP_LAN_OFF_IND_ID));

    add(sdUnmountedInd);
    add(sdMountedInd);
    add(ethernetConnectedInd);
    add(ethernetDisconnectedInd);
}

void PeripheralStateIndicatorsBase::initialize()
{

}

