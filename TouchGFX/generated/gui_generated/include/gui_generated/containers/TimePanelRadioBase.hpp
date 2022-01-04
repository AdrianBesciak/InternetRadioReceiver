/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEPANELRADIOBASE_HPP
#define TIMEPANELRADIOBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class TimePanelRadioBase : public touchgfx::Container
{
public:
    TimePanelRadioBase();
    virtual ~TimePanelRadioBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard timeCurrentText;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TIMECURRENTTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeCurrentTextBuffer[TIMECURRENTTEXT_SIZE];

private:

};

#endif // TIMEPANELRADIOBASE_HPP
