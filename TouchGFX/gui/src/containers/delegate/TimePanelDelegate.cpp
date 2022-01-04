#include <gui/containers/delegate/TimePanelDelegate.hpp>

TimePanelDelegate::~TimePanelDelegate() = default;

void TimePanelDelegate::setTime(float currentTime, float totalTime) {
    getTimePanel().setTime(currentTime, totalTime);
}
