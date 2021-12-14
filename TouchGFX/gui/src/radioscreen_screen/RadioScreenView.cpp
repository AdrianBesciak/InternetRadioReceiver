#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView()
    : title() {
}


void RadioScreenView::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    radioControlPanel1.setOnPlayClicked(onPlayClicked);
}

void RadioScreenView::setOnStopClicked(const std::function<void()> &onStopClicked) {
    radioControlPanel1.setOnStopClicked(onStopClicked);
}


void RadioScreenView::setPeripheralState(bool ethernetState, bool sdCardState) {
    controls1.setEthernetState(ethernetState);
    controls1.setSdCardState(sdCardState);
}


void RadioScreenView::setTitle(const std::string &title) {
    if (this->title != title) {
        this->title = title;
        static Unicode::UnicodeChar buff[RADIOSTATIONNAMEBOX_SIZE];
        Unicode::strncpy(buff, title.c_str(), RADIOSTATIONNAMEBOX_SIZE);
        Unicode::snprintf(radioStationNameBoxBuffer, RADIOSTATIONNAMEBOX_SIZE, "%s", buff);
        radioStationNameBox.invalidate();
    }
}

void RadioScreenView::setPlayVisible(bool visible) {
    radioControlPanel1.setPlayVisible(visible);
}

void RadioScreenView::setStopVisible(bool visible) {
    radioControlPanel1.setStopVisible(visible);
}



void RadioScreenView::fillRadioStationsList(const std::vector<model::RadioStationsListModel::Entry>& stations, const uint8_t currentStation){
    for (std::size_t i = 0; i < stations.size(); i++)
    {
        RadioStationsListItems[i].setName(stations[i].getName());
    }
}
