#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void changeSdCardIndicator(bool sdState);
    void changeEthernetIndicator(bool ethernetState);
protected:
    //void handleTickEvent();
};

#endif // MAINVIEW_HPP
