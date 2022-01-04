#pragma once
#include <gui_generated/containers/TimePanelSDBase.hpp>
#include <gui/containers/interface/TimePanelInterface.hpp>

class TimePanelSD : public TimePanelSDBase
        , public TimePanelInterface {
public:
    TimePanelSD();
    void setTime(float currentTime, float totalTime) override;
private:
    float storedCurrentTime;
    float storedTotalTime;
    std::uint32_t storedProgress;
};
