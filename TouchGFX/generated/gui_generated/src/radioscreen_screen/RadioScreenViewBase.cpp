/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

RadioScreenViewBase::RadioScreenViewBase() :
    buttonCallback(this, &RadioScreenViewBase::buttonCallbackHandler),
    updateItemCallback(this, &RadioScreenViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    RadioIcon.setXY(20, 20);
    RadioIcon.setBitmap(touchgfx::Bitmap(BITMAP_RADIO_ID));

    controls1.setXY(370, 10);

    radioControlPanel1.setXY(190, 200);

    radioStationNameBox.setPosition(37, 124, 404, 25);
    radioStationNameBox.setColor(touchgfx::Color::getColorFromRGB(129, 133, 255));
    radioStationNameBox.setLinespacing(0);
    Unicode::snprintf(radioStationNameBoxBuffer, RADIOSTATIONNAMEBOX_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ZKCH).getText());
    radioStationNameBox.setWildcard(radioStationNameBoxBuffer);
    radioStationNameBox.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QX2T));

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
    SDCardMenu.setBitmaps(touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_ID), touchgfx::Bitmap(BITMAP_SDCARD_BUTTON_PRESSED_ID));
    SDCardMenu.setAction(buttonCallback);
    slideMenuLeft.add(SDCardMenu);

    radioMenu.setXY(0, 0);
    radioMenu.setBitmaps(touchgfx::Bitmap(BITMAP_RADIO_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_RADIO_BUTTON_PRESSED_ID));
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

    RadioStations.setPosition(27, 2, 170, 272);
    RadioStations.setHorizontal(false);
    RadioStations.setCircular(false);
    RadioStations.setEasingEquation(touchgfx::EasingEquations::quadEaseInOut);
    RadioStations.setSwipeAcceleration(10);
    RadioStations.setDragAcceleration(10);
    RadioStations.setNumberOfItems(10);
    RadioStations.setSelectedItemOffset(0);
    RadioStations.setDrawableSize(30, 0);
    RadioStations.setDrawables(RadioStationsListItems, updateItemCallback);
    RadioStations.animateToItem(0, 0);
    slideMenuRight.add(RadioStations);

    add(__background);
    add(RadioIcon);
    add(controls1);
    add(radioControlPanel1);
    add(radioStationNameBox);
    add(slideMenuLeft);
    add(slideMenuRight);
}

void RadioScreenViewBase::setupScreen()
{
    controls1.initialize();
    radioControlPanel1.initialize();
    RadioStations.initialize();
    for (int i = 0; i < RadioStationsListItems.getNumberOfDrawables(); i++)
    {
        RadioStationsListItems[i].initialize();
    }
}

void RadioScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &SDCardMenu)
    {
        //sdCardMenuOnClick
        //When SDCardMenu clicked change screen to MemoryScreen
        //Go to MemoryScreen with no screen transition
        application().gotoMemoryScreenScreenNoTransition();
    }
}

void RadioScreenViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &RadioStationsListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        listItem_notSelected* cc = (listItem_notSelected*)d;
        RadioStationsUpdateItem(*cc, itemIndex);
    }
}
