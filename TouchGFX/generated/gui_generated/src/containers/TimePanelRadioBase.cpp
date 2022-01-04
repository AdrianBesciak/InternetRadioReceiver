/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/TimePanelRadioBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

TimePanelRadioBase::TimePanelRadioBase()
{
    setWidth(60);
    setHeight(25);
    timeCurrentText.setXY(0, 0);
    timeCurrentText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    timeCurrentText.setLinespacing(0);
    Unicode::snprintf(timeCurrentTextBuffer, TIMECURRENTTEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RZ5K).getText());
    timeCurrentText.setWildcard(timeCurrentTextBuffer);
    timeCurrentText.resizeToCurrentText();
    timeCurrentText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PAK3));

    add(timeCurrentText);
}

void TimePanelRadioBase::initialize()
{

}
