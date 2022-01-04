#pragma once
#include <gui/containers/ControlPanelSD.hpp>


class ControlPanelSDDelegate {
public:
    virtual ~ControlPanelSDDelegate();

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);
    void setOnPauseClicked(const std::function<void()> &onPauseClicked);
    void setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked);
    void setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked);
    void setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked);
    void setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked);
    void setPlayVisible(bool visible);
    void setPauseVisible(bool visible);

protected:
    virtual ControlPanelSD& getControlPanel() = 0;
};


