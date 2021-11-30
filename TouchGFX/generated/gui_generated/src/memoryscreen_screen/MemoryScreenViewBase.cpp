/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/memoryscreen_screen/MemoryScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MemoryScreenViewBase::MemoryScreenViewBase() :
    buttonCallback(this, &MemoryScreenViewBase::buttonCallbackHandler),
    updateItemCallback(this, &MemoryScreenViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    MemoryIcon.setXY(20, 20);
    MemoryIcon.setBitmap(touchgfx::Bitmap(BITMAP_RAW_MICRO_SD_ID));

    controls1.setXY(370, 10);

    musicControlPanel1.setXY(65, 200);

    songProgressBar.setXY(37, 158);
    songProgressBar.setProgressIndicatorPosition(2, 2, 400, 30);
    songProgressBar.setRange(0, 100);
    songProgressBar.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    songProgressBar.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_LARGE_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID));
    songProgressBar.setBitmap(BITMAP_BLUE_PROGRESSINDICATORS_FILL_TILING_PROGRESS_INDICATOR_FILL_STRIPED_WIDE_HORIZONTAL_ID);
    songProgressBar.setValue(60);
    songProgressBar.setAnchorAtZero(false);

    filenameTextBox.setPosition(37, 133, 404, 25);
    filenameTextBox.setColor(touchgfx::Color::getColorFromRGB(129, 133, 255));
    filenameTextBox.setLinespacing(0);
    Unicode::snprintf(filenameTextBoxBuffer, FILENAMETEXTBOX_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_XX3O).getText());
    filenameTextBox.setWildcard(filenameTextBoxBuffer);
    filenameTextBox.setTypedText(touchgfx::TypedText(T___SINGLEUSE_085C));

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
    slideMenuLeft.setExpandedStateTimeout(180);
    slideMenuLeft.setXY(0, 0);

    SDCardMenu.setXY(0, 50);
    SDCardMenu.setBitmaps(touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_PRESSED_ID));
    slideMenuLeft.add(SDCardMenu);

    radioMenu.setXY(0, 0);
    radioMenu.setBitmaps(touchgfx::Bitmap(BITMAP_RADIO_BUTTON_01_ID), touchgfx::Bitmap(BITMAP_RADIO_BUTTON_PRESSED_ID));
    radioMenu.setAction(buttonCallback);
    slideMenuLeft.add(radioMenu);

    slideMenuRight.setup(touchgfx::SlideMenu::WEST,
        touchgfx::Bitmap(BITMAP_RIGHT_SLIDE_MENU_BACKGROUND_ID),
        touchgfx::Bitmap(BITMAP_RIGHT_SLIDE_MENU_BUTTON_ID),
        touchgfx::Bitmap(BITMAP_RIGHT_SLIDE_MENU_BUTTON_ID),
        18, 0, 0, 110);
    slideMenuRight.setState(touchgfx::SlideMenu::COLLAPSED);
    slideMenuRight.setVisiblePixelsWhenCollapsed(25);
    slideMenuRight.setHiddenPixelsWhenExpanded(0);
    slideMenuRight.setAnimationEasingEquation(touchgfx::EasingEquations::cubicEaseInOut);
    slideMenuRight.setAnimationDuration(18);
    slideMenuRight.setExpandedStateTimeout(180);
    slideMenuRight.setXY(280, 0);

    PlayQueue.setPosition(27, 2, 170, 272);
    PlayQueue.setHorizontal(false);
    PlayQueue.setCircular(true);
    PlayQueue.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    PlayQueue.setSwipeAcceleration(10);
    PlayQueue.setDragAcceleration(10);
    PlayQueue.setNumberOfItems(20);
    PlayQueue.setSelectedItemOffset(14);
    PlayQueue.setSelectedItemExtraSize(0, 0);
    PlayQueue.setSelectedItemMargin(2, 2);
    PlayQueue.setDrawableSize(30, 0);
    PlayQueue.setDrawables(PlayQueueListItems, updateItemCallback,
                              PlayQueueSelectedListItems, updateItemCallback);
    PlayQueue.animateToItem(10, 0);
    slideMenuRight.add(PlayQueue);

    add(__background);
    add(MemoryIcon);
    add(controls1);
    add(musicControlPanel1);
    add(songProgressBar);
    add(filenameTextBox);
    add(slideMenuLeft);
    add(slideMenuRight);
}

void MemoryScreenViewBase::setupScreen()
{
    controls1.initialize();
    musicControlPanel1.initialize();
    PlayQueue.initialize();
    for (int i = 0; i < PlayQueueListItems.getNumberOfDrawables(); i++)
    {
        PlayQueueListItems[i].initialize();
    }
    for (int i = 0; i < PlayQueueSelectedListItems.getNumberOfDrawables(); i++)
    {
        PlayQueueSelectedListItems[i].initialize();
    }
}

void MemoryScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioMenu)
    {
        //radioScreenOnClick
        //When radioMenu clicked change screen to RadioScreen
        //Go to RadioScreen with no screen transition
        application().gotoRadioScreenScreenNoTransition();
    }
}

void MemoryScreenViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &PlayQueueListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        listItem_notSelected* cc = (listItem_notSelected*)d;
        PlayQueueUpdateItem(*cc, itemIndex);
    }
    else if (items == &PlayQueueSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        listItem_selected* cc = (listItem_selected*)d;
        PlayQueueUpdateCenterItem(*cc, itemIndex);
    }
}
