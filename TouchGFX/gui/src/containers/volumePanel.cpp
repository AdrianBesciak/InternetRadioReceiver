#include <gui/containers/volumePanel.hpp>

volumePanel::volumePanel()
    : onVolumePlusClicked(nullptr)
    , onVolumeMinusClicked(nullptr) {};

void volumePanel::setOnVolumePlusClicked(const std::function<void()> &onVolumePlusClicked) {
    volumePanel::onVolumePlusClicked = onVolumePlusClicked;
}

void volumePanel::setOnVolumeMinusClicked(const std::function<void()> &onVolumeMinusClicked) {
    volumePanel::onVolumeMinusClicked = onVolumeMinusClicked;
}

void volumePanel::handleVolumePlusClicked() {
    if (onVolumePlusClicked != nullptr) {
        onVolumePlusClicked();
    }
}

void volumePanel::handleVolumeMinusClicked() {
    if (onVolumeMinusClicked != nullptr) {
        onVolumeMinusClicked();
    }
}
