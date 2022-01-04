#include <gui/containers/VolumePanel.hpp>

VolumePanel::VolumePanel()
    : storedVolume(0)
    , onVolumePlusClicked(nullptr)
    , onVolumeMinusClicked(nullptr) {}


void VolumePanel::setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked) {
    this->onVolumePlusClicked = onVolumePlusClicked;
}

void VolumePanel::setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked) {
    this->onVolumeMinusClicked = onVolumeMinusClicked;
}


void VolumePanel::setVolume(std::uint32_t volume) {
    if (volume != storedVolume) {
        storedVolume = volume;
        Unicode::snprintf(volumeTextBuffer, VOLUMETEXT_SIZE, "%u", volume);
        volumeText.invalidate();
    }
}


void VolumePanel::handleVolumePlusClicked() {
    if (onVolumePlusClicked != nullptr) {
        onVolumePlusClicked();
    }
}

void VolumePanel::handleVolumeMinusClicked() {
    if (onVolumeMinusClicked != nullptr) {
        onVolumeMinusClicked();
    }
}
