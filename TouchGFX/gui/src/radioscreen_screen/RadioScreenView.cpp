#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView() = default;

PeripheralStateIndicators& RadioScreenView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}

VolumePanel& RadioScreenView::getVolumePanel() {
    return volumePanel;
}

TitleView& RadioScreenView::getTitleView() {
    return titleView;
}

TimePanelRadio& RadioScreenView::getTimePanel() {
    return timePanel;
}

ControlPanelRadio& RadioScreenView::getControlPanel() {
    return controlPanel;
}

Playlist& RadioScreenView::getPlaylist() {
    return playlist;
}

ErrorDialog& RadioScreenView::getErrorDialog() {
    return errorDialog;
}
