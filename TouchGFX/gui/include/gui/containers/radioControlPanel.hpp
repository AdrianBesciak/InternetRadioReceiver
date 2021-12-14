#pragma once
#include <gui_generated/containers/radioControlPanelBase.hpp>
#include <functional>

class radioControlPanel : public radioControlPanelBase {
public:
    radioControlPanel();

    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);

protected:
    void handlePlayClicked() override;
    void handleStopClicked() override;

private:
    std::function<void()> onPlayClicked;
    std::function<void()> onStopClicked;
};
