#pragma once
#include <gui_generated/containers/ControlPanelSDBase.hpp>
#include <functional>

class ControlPanelSD : public ControlPanelSDBase {
public:
    ControlPanelSD();

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
    void handlePlayClicked() override;
    void handleStopClicked() override;
    void handlePauseClicked() override;
    void handleFastForwardClicked() override;
    void handleFastBackwardClicked() override;
    void handlePlayNextClicked() override;
    void handlePlayPreviousClicked() override;

private:
    std::function<void()> onPlayClicked;
    std::function<void()> onStopClicked;
    std::function<void()> onPauseClicked;
    std::function<void()> onFastForwardClicked;
    std::function<void()> onFastBackwardClicked;
    std::function<void()> onPlayNextClicked;
    std::function<void()> onPlayPreviousClicked;
};
