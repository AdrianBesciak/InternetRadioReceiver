#pragma once
#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>

class MainScreenView : public MainScreenViewBase
        , public PeripheralStateIndicatorsDelegate {
public:
    MainScreenView();
protected:
    PeripheralStateIndicators &getPeripheralStateIndicators() override;
};
