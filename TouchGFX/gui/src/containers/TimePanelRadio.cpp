#include <gui/containers/TimePanelRadio.hpp>

TimePanelRadio::TimePanelRadio()
    : storedCurrentTime(0.0f) {}

void TimePanelRadio::setTime(float currentTime, float totalTime) {
    std::ignore = totalTime;
    if (std::abs(currentTime - storedCurrentTime) >= 1.0f) {
        storedCurrentTime = currentTime;
        auto timeInteger = static_cast<std::uint32_t>(currentTime);
        auto seconds = timeInteger % 60;
        auto minutes = timeInteger / 60;
        Unicode::snprintf(timeCurrentTextBuffer, TIMECURRENTTEXT_SIZE, "%u:%u", minutes, seconds);
        timeCurrentText.invalidate();
    }
}
