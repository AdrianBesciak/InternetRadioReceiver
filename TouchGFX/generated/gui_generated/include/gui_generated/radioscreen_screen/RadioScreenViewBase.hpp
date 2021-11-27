/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RADIOSCREENVIEWBASE_HPP
#define RADIOSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <gui/containers/controls.hpp>
#include <gui/containers/radioControlPanel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/Button.hpp>

class RadioScreenViewBase : public touchgfx::View<RadioScreenPresenter>
{
public:
    RadioScreenViewBase();
    virtual ~RadioScreenViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image RadioIcon;
    controls controls1;
    radioControlPanel radioControlPanel1;
    touchgfx::TextArea radioStationNameBox;
    touchgfx::SlideMenu slideMenuLeft;
    touchgfx::Button SDCardMenu;
    touchgfx::Button radioMenu;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<RadioScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // RADIOSCREENVIEWBASE_HPP