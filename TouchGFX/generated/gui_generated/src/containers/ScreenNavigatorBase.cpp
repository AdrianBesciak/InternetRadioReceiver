/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ScreenNavigatorBase.hpp>
#include <BitmapDatabase.hpp>

ScreenNavigatorBase::ScreenNavigatorBase() :
    buttonCallback(this, &ScreenNavigatorBase::buttonCallbackHandler)
{
    setWidth(74);
    setHeight(272);
    slideMenuLeft.setup(touchgfx::SlideMenu::EAST,
        touchgfx::Bitmap(BITMAP_LEFT_SLIDE_MENU_BACKGROUND_ID),
        touchgfx::Bitmap(BITMAP_LEFT_SLIDE_MENU_BUTTON_ID),
        touchgfx::Bitmap(BITMAP_LEFT_SLIDE_MENU_BUTTON_ID),
        0, 0, 50, 110);
    slideMenuLeft.setState(touchgfx::SlideMenu::COLLAPSED);
    slideMenuLeft.setVisiblePixelsWhenCollapsed(25);
    slideMenuLeft.setHiddenPixelsWhenExpanded(0);
    slideMenuLeft.setAnimationEasingEquation(touchgfx::EasingEquations::cubicEaseInOut);
    slideMenuLeft.setAnimationDuration(18);
    slideMenuLeft.setExpandedStateTimeout(0);
    slideMenuLeft.setXY(0, 0);

    sdCardButton.setXY(0, 50);
    sdCardButton.setBitmaps(touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_ID), touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_PRESSED_ID));
    sdCardButton.setAction(buttonCallback);
    slideMenuLeft.add(sdCardButton);

    radioButton.setXY(0, 0);
    radioButton.setBitmaps(touchgfx::Bitmap(BITMAP_RADIO_BUTTON_01_ID), touchgfx::Bitmap(BITMAP_RADIO_BUTTON_PRESSED_ID));
    radioButton.setAction(buttonCallback);
    slideMenuLeft.add(radioButton);

    add(slideMenuLeft);
}

void ScreenNavigatorBase::initialize()
{

}

void ScreenNavigatorBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &sdCardButton)
    {
        //sdCardButtonClicked
        //When sdCardButton clicked change screen to SDCardScreen
        //Go to SDCardScreen with no screen transition
        application().gotoSDCardScreenScreenNoTransition();
    }
    else if (&src == &radioButton)
    {
        //radioButtonClicked
        //When radioButton clicked change screen to RadioScreen
        //Go to RadioScreen with no screen transition
        application().gotoRadioScreenScreenNoTransition();
    }
}

