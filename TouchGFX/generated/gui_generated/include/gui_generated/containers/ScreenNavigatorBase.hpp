/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENNAVIGATORBASE_HPP
#define SCREENNAVIGATORBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/Button.hpp>

class ScreenNavigatorBase : public touchgfx::Container
{
public:
    ScreenNavigatorBase();
    virtual ~ScreenNavigatorBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::SlideMenu slideMenuLeft;
    touchgfx::Button sdCardButton;
    touchgfx::Button radioButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ScreenNavigatorBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREENNAVIGATORBASE_HPP
