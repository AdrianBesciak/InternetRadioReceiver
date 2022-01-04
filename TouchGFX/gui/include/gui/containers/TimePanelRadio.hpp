#pragma once
#include <gui_generated/containers/TimePanelRadioBase.hpp>
#include <gui/containers/interface/TimePanelInterface.hpp>

class TimePanelRadio : public TimePanelRadioBase
        , public TimePanelInterface {
public:
    TimePanelRadio();
    void setTime(float currentTime, float totalTime) override;

private:
    float storedCurrentTime;
};
