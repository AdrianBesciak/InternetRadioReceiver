#pragma once
#include <gui_generated/containers/volumePanelBase.hpp>
#include <functional>

class volumePanel : public volumePanelBase {
public:
    volumePanel();

    void setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked);
    void setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked);

protected:
    void handleVolumePlusClicked() override;
    void handleVolumeMinusClicked() override;

private:
    std::function<void()> onVolumePlusClicked;
    std::function<void()> onVolumeMinusClicked;
};
