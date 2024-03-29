/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMEPANELSDBASE_HPP
#define TIMEPANELSDBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/progress_indicators/ImageProgress.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class TimePanelSDBase : public touchgfx::Container
{
public:
    TimePanelSDBase();
    virtual ~TimePanelSDBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::ImageProgress progressBar;
    touchgfx::TextAreaWithOneWildcard timeTotalText;
    touchgfx::TextAreaWithOneWildcard timeCurrentText;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TIMETOTALTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeTotalTextBuffer[TIMETOTALTEXT_SIZE];
    static const uint16_t TIMECURRENTTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeCurrentTextBuffer[TIMECURRENTTEXT_SIZE];

private:

};

#endif // TIMEPANELSDBASE_HPP
