/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/listItem_selectedBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

listItem_selectedBase::listItem_selectedBase() :
    trigger1Callback(0)
{
    setWidth(170);
    setHeight(30);
    flexButton1.setBoxWithBorderPosition(0, 0, 170, 30);
    flexButton1.setBorderSize(2);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(34, 37, 43), touchgfx::Color::getColorFromRGB(34, 37, 43), touchgfx::Color::getColorFromRGB(186, 193, 204), touchgfx::Color::getColorFromRGB(186, 193, 204));
    flexButton1.setPosition(0, 0, 170, 30);

    FileName.setPosition(5, 4, 160, 22);
    FileName.setColor(touchgfx::Color::getColorFromRGB(242, 243, 247));
    FileName.setLinespacing(0);
    FileName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2RLI));

    add(flexButton1);
    add(FileName);
}

void listItem_selectedBase::initialize()
{

}

