#pragma once


class TimePanelInterface {
public:
    virtual ~TimePanelInterface();
    virtual void setTime(float currentTime, float totalTime) = 0;
};


