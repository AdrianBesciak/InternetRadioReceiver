#pragma once
#include <gui/containers/VolumePanel.hpp>

class VolumePanelDelegate {
public:
    virtual ~VolumePanelDelegate();

    void setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked);
    void setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked);
    void setVolume(std::uint32_t volume);

protected:
    virtual VolumePanel& getVolumePanel() = 0;
};


