#include <gui/containers/TimePanelSD.hpp>
#include <cmath>

TimePanelSD::TimePanelSD()
    : storedCurrentTime(0.0f)
    , storedTotalTime(0.0f)
    , storedProgress(0) {}

void TimePanelSD::setTime(float currentTime, float totalTime) {
    if (std::abs(currentTime - storedCurrentTime) >= 0.9f) {
        storedCurrentTime = currentTime;
        auto timeInteger = static_cast<std::uint32_t>(storedCurrentTime);
        auto seconds = timeInteger % 60;
        auto minutes = timeInteger / 60;
        Unicode::snprintf(timeCurrentTextBuffer, TIMECURRENTTEXT_SIZE, "%02u:%02u", minutes, seconds);
        timeCurrentText.invalidate();
    }
    if (std::abs(totalTime - storedTotalTime) >= 0.9f) {
        storedTotalTime = totalTime;
        auto timeInteger = static_cast<std::uint32_t>(storedTotalTime);
        auto seconds = timeInteger % 60;
        auto minutes = timeInteger / 60;
        Unicode::snprintf(timeTotalTextBuffer, TIMETOTALTEXT_SIZE, "%02u:%02u", minutes, seconds);
        timeTotalText.invalidate();
    }
    auto progress = static_cast<std::uint32_t>(std::round(currentTime / totalTime * 100));
    if (progress != storedProgress) {
        storedProgress = progress;
        progressBar.setValue(static_cast<int>(storedProgress));
        progressBar.invalidate();
    }
}
