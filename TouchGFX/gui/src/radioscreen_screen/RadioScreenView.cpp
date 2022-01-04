#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView() = default;

void RadioScreenView::fillRadioStationsList(const std::vector<model::RadioStationsListModel::Entry>& stations, std::uint8_t currentStation){
    for (std::size_t i = 0; i < stations.size(); i++) {
        RadioStationsListItems[static_cast<int>(i)].setName(stations[i].getName());
    }
}


PeripheralStateIndicators& RadioScreenView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}

VolumePanel& RadioScreenView::getVolumePanel() {
    return volumePanel;
}

TitleView& RadioScreenView::getTitleView() {
    return titleView;
}

TimePanelInterface& RadioScreenView::getTimePanel() {
    return timePanel;
}

ControlPanelRadio& RadioScreenView::getControlPanel() {
    return controlPanel;
}
