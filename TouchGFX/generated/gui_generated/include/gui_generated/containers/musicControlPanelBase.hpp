/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MUSICCONTROLPANELBASE_HPP
#define MUSICCONTROLPANELBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/mixins/ClickListener.hpp>

class musicControlPanelBase : public touchgfx::Container
{
public:
    musicControlPanelBase();
    virtual ~musicControlPanelBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::ClickListener< touchgfx::Button > play;
    touchgfx::ClickListener< touchgfx::Button > stop;
    touchgfx::ClickListener< touchgfx::Button > pause;
    touchgfx::ClickListener< touchgfx::Button > backward;
    touchgfx::ClickListener< touchgfx::Button > previousSong;
    touchgfx::ClickListener< touchgfx::Button > forward;
    touchgfx::ClickListener< touchgfx::Button > nextSong;

private:

};

#endif // MUSICCONTROLPANELBASE_HPP
