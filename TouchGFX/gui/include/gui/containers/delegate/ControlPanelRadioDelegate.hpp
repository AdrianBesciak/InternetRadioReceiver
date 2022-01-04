#pragma once
#include <gui/containers/ControlPanelRadio.hpp>

class ControlPanelRadioDelegate {
public:
    virtual ~ControlPanelRadioDelegate();

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);
    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);

protected:
    virtual ControlPanelRadio& getControlPanel() = 0;
};


