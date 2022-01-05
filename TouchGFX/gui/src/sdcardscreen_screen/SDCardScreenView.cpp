#include <gui/sdcardscreen_screen/SDCardScreenView.hpp>

SDCardScreenView::SDCardScreenView() = default;

PeripheralStateIndicators& SDCardScreenView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}

VolumePanel& SDCardScreenView::getVolumePanel() {
    return volumePanel;
}

TitleView& SDCardScreenView::getTitleView() {
    return titleView;
}

TimePanelSD& SDCardScreenView::getTimePanel() {
    return timePanel;
}

ControlPanelSD& SDCardScreenView::getControlPanel() {
    return controlPanel;
}

Playlist& SDCardScreenView::getPlaylist() {
    return playlist;
}

ErrorDialog& SDCardScreenView::getErrorDialog() {
    return errorDialog;
}
