#pragma once
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>

class MainView : public MainViewBase
        , public PeripheralStateIndicatorsDelegate {
public:
    MainView();

protected:
    PeripheralStateIndicators &getPeripheralStateIndicators() override;
};
