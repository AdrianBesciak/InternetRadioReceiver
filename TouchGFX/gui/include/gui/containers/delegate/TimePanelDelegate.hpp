#pragma once
#include <gui/containers/interface/TimePanelInterface.hpp>

class TimePanelDelegate {
public:
    virtual ~TimePanelDelegate();

    void setTime(float currentTime, float totalTime);

protected:
    virtual TimePanelInterface& getTimePanel() = 0;
};


