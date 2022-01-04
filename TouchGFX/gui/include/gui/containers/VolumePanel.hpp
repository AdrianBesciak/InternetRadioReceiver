#pragma once
#include <gui_generated/containers/VolumePanelBase.hpp>
#include <functional>

class VolumePanel : public VolumePanelBase {
public:
    VolumePanel();

    void setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked);
    void setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked);

    void setVolume(std::uint32_t volume);

protected:
    void handleVolumePlusClicked() override;
    void handleVolumeMinusClicked() override;

private:
    std::uint32_t storedVolume;
    std::function<void()> onVolumePlusClicked;
    std::function<void()> onVolumeMinusClicked;
};
