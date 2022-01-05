/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ErrorDialogBase.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

ErrorDialogBase::ErrorDialogBase() :
    buttonCallback(this, &ErrorDialogBase::buttonCallbackHandler)
{
    setWidth(320);
    setHeight(240);
    modalWindow.setBackground(touchgfx::BitmapId(BITMAP_DARK_BACKGROUNDS_MAIN_BG_320X240PX_ID), 0, 0);
    modalWindow.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    dismissButton.setXY(149, 180);
    dismissButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    dismissButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_T1MO));
    dismissButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dismissButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dismissButton.setAction(buttonCallback);
    modalWindow.add(dismissButton);

    errorMessageText.setPosition(10, 56, 302, 115);
    errorMessageText.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    errorMessageText.setLinespacing(0);
    Unicode::snprintf(errorMessageTextBuffer, ERRORMESSAGETEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0XSM).getText());
    errorMessageText.setWildcard(errorMessageTextBuffer);
    errorMessageText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J9NG));
    modalWindow.add(errorMessageText);

    errorTitleText.setPosition(55, 5, 257, 41);
    errorTitleText.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    errorTitleText.setLinespacing(0);
    errorTitleText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F3DJ));
    modalWindow.add(errorTitleText);

    image1.setXY(7, 5);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_ICONS_ALERT_48_ID));
    modalWindow.add(image1);

    add(modalWindow);
}

void ErrorDialogBase::initialize()
{

}

void ErrorDialogBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &dismissButton)
    {
        //dismissButtonClicked
        //When dismissButton clicked call virtual function
        //Call handleDismissButtonClicked
        handleDismissButtonClicked();
    }
}
