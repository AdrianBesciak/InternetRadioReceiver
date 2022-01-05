#pragma once
#include <gui_generated/containers/TimePanelSDBase.hpp>

class TimePanelSD : public TimePanelSDBase {
public:
    TimePanelSD();
    void setTime(float currentTime, float totalTime);
private:
    float storedCurrentTime;
    float storedTotalTime;
    std::uint32_t storedProgress;
};
