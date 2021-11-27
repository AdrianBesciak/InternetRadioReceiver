/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RADIOCONTROLPANELBASE_HPP
#define RADIOCONTROLPANELBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/mixins/ClickListener.hpp>

class radioControlPanelBase : public touchgfx::Container
{
public:
    radioControlPanelBase();
    virtual ~radioControlPanelBase() {}
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

private:

};

#endif // RADIOCONTROLPANELBASE_HPP