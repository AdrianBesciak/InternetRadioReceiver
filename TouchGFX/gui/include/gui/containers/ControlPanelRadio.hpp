#pragma once
#include <gui_generated/containers/ControlPanelRadioBase.hpp>
#include <functional>

class ControlPanelRadio : public ControlPanelRadioBase {
public:
    ControlPanelRadio();

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);

    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);

protected:
    void handlePlayClicked() override;
    void handleStopClicked() override;

private:
    std::function<void()> onPlayClicked;
    std::function<void()> onStopClicked;
};
