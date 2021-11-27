#ifndef RADIOSCREENVIEW_HPP
#define RADIOSCREENVIEW_HPP

#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>

class RadioScreenView : public RadioScreenViewBase
{
public:
    RadioScreenView();
    virtual ~RadioScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    controls& getControls();
protected:
};

#endif // RADIOSCREENVIEW_HPP
