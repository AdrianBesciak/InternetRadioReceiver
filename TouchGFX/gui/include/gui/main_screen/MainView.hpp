#pragma once
#include <gui_generated/main_screen/MainViewBase.hpp>

class MainView : public MainViewBase {
public:
    MainView();
    void setPeripheralState(bool ethernetState, bool sdCardState);
};
