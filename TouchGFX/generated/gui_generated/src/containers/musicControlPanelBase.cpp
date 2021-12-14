/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/musicControlPanelBase.hpp>
#include <BitmapDatabase.hpp>

musicControlPanelBase::musicControlPanelBase() :
    buttonCallback(this, &musicControlPanelBase::buttonCallbackHandler)
{
    setWidth(350);
    setHeight(50);
    play.setXY(120, 0);
    play.setBitmaps(touchgfx::Bitmap(BITMAP_PLAY_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_PLAY_BUTTON_INACTIVE_ID));
    play.setAction(buttonCallback);

    stop.setXY(175, 0);
    stop.setBitmaps(touchgfx::Bitmap(BITMAP_STOP_ACTIVE_ID), touchgfx::Bitmap(BITMAP_STOP_INACTIVE_ID));
    stop.setAction(buttonCallback);

    pause.setXY(120, 0);
    pause.setBitmaps(touchgfx::Bitmap(BITMAP_PAUSE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_PAUSE_INACTIVE_ID));
    pause.setAction(buttonCallback);

    backward.setXY(60, 0);
    backward.setBitmaps(touchgfx::Bitmap(BITMAP_BACKWARD_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BACKWARD_INACTIVE_ID));
    backward.setAction(buttonCallback);

    previousSong.setXY(0, 0);
    previousSong.setBitmaps(touchgfx::Bitmap(BITMAP_PREVIOUS_SONG_ACTIVE_ID), touchgfx::Bitmap(BITMAP_PREVIOUS_SONG_INACTIVE_ID));
    previousSong.setAction(buttonCallback);

    forward.setXY(240, 0);
    forward.setBitmaps(touchgfx::Bitmap(BITMAP_FORWARD_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_FORWARD_BUTTON_INACTIVE_ID));
    forward.setAction(buttonCallback);

    nextSong.setXY(300, 0);
    nextSong.setBitmaps(touchgfx::Bitmap(BITMAP_NEXT_SONG_ACTIVE_ID), touchgfx::Bitmap(BITMAP_NEXT_SONG_INACTIVE_ID));
    nextSong.setAction(buttonCallback);

    add(play);
    add(stop);
    add(pause);
    add(backward);
    add(previousSong);
    add(forward);
    add(nextSong);
}

void musicControlPanelBase::initialize()
{

}

void musicControlPanelBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
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
    else if (&src == &pause)
    {
        //pauseClicked
        //When pause clicked call virtual function
        //Call handlePauseClicked
        handlePauseClicked();
    }
    else if (&src == &backward)
    {
        //fastBackwardClicked
        //When backward clicked call virtual function
        //Call handleFastBackwardClicked
        handleFastBackwardClicked();
    }
    else if (&src == &previousSong)
    {
        //playPreviousClicked
        //When previousSong clicked call virtual function
        //Call handlePlayPreviousClicked
        handlePlayPreviousClicked();
    }
    else if (&src == &forward)
    {
        //fastForwardClicked
        //When forward clicked call virtual function
        //Call handleFastForwardClicked
        handleFastForwardClicked();
    }
    else if (&src == &nextSong)
    {
        //playNextClicked
        //When nextSong clicked call virtual function
        //Call handlePlayNextClicked
        handlePlayNextClicked();
    }
}

