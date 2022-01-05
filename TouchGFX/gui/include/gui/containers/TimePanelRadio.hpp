#pragma once
#include <gui_generated/containers/TimePanelRadioBase.hpp>

class TimePanelRadio : public TimePanelRadioBase {
public:
    TimePanelRadio();
    void setTime(float currentTime, float totalTime);

private:
    float storedCurrentTime;
};
