#include <gui/containers/delegate/VolumePanelDelegate.hpp>

VolumePanelDelegate::~VolumePanelDelegate() = default;

void VolumePanelDelegate::setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked) {
    getVolumePanel().setOnVolumePlusClicked(onVolumePlusClicked);
}

void VolumePanelDelegate::setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked) {
    getVolumePanel().setOnVolumeMinusClicked(onVolumeMinusClicked);
}

void VolumePanelDelegate::setVolume(std::uint32_t volume) {
    getVolumePanel().setVolume(volume);
}
