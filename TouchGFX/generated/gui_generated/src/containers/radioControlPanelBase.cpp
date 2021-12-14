/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/radioControlPanelBase.hpp>
#include <BitmapDatabase.hpp>

radioControlPanelBase::radioControlPanelBase() :
    buttonCallback(this, &radioControlPanelBase::buttonCallbackHandler)
{
    setWidth(50);
    setHeight(50);
    play.setXY(0, 0);
    play.setBitmaps(touchgfx::Bitmap(BITMAP_PLAY_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_PLAY_BUTTON_INACTIVE_ID));
    play.setAction(buttonCallback);

    stop.setXY(0, 0);
    stop.setBitmaps(touchgfx::Bitmap(BITMAP_STOP_ACTIVE_ID), touchgfx::Bitmap(BITMAP_STOP_INACTIVE_ID));
    stop.setAction(buttonCallback);

    add(play);
    add(stop);
}

void radioControlPanelBase::initialize()
{

}

void radioControlPanelBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &play)
    {
        //playClicked
        //When play clicked call virtual function
        //Call handlePlayClicked
        handlePlayClicked();
    }
    else if (&src == &stop)
    {
        //stopClicked
        //When stop clicked call virtual function
        //Call handleStopClicked
        handleStopClicked();
    }
}

