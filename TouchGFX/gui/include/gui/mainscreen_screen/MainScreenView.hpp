#pragma once
#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase {
public:
    MainScreenView();
    PeripheralStateIndicators &getPeripheralStateIndicators();
};
