#pragma once
#include <gui_generated/memoryscreen_screen/MemoryScreenViewBase.hpp>

class MemoryScreenView : public MemoryScreenViewBase {
public:
    MemoryScreenView();

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);
    void setOnPauseClicked(const std::function<void()> &onPauseClicked);
    void setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked);
    void setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked);
    void setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked);
    void setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked);

    void setPeripheralState(bool ethernetState, bool sdCardState);
};
