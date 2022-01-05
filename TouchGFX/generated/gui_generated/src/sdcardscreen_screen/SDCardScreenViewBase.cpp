/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/sdcardscreen_screen/SDCardScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

SDCardScreenViewBase::SDCardScreenViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    controlPanel.setXY(65, 200);

    timePanel.setXY(28, 160);

    titleView.setXY(40, 125);

    volumePanel.setXY(95, 15);

    peripheralStateIndicators.setXY(370, 10);

    sdCardIcon.setXY(20, 20);
    sdCardIcon.setBitmap(touchgfx::Bitmap(BITMAP_RAW_MICRO_SD_ID));

    playlist.setXY(278, 0);

    screenNavigator.setXY(0, 0);

    add(__background);
    add(controlPanel);
    add(timePanel);
    add(titleView);
    add(volumePanel);
    add(peripheralStateIndicators);
    add(sdCardIcon);
    add(playlist);
    add(screenNavigator);
}

void SDCardScreenViewBase::setupScreen()
{
    controlPanel.initialize();
    timePanel.initialize();
    titleView.initialize();
    volumePanel.initialize();
    peripheralStateIndicators.initialize();
    playlist.initialize();
    screenNavigator.initialize();
}
