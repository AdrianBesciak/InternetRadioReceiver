#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView()
    : title() {
}

controls &RadioScreenView::getControls() {
    return controls1;
}

void RadioScreenView::setTitle(const std::string &title) {
    if (this->title != title) {
        this->title = title;
        static Unicode::UnicodeChar buff[20];
        Unicode::strncpy(buff, title.c_str(), 20);
        Unicode::snprintf(radioStationNameBoxBuffer, 20, "%s", buff);
        radioStationNameBox.invalidate();
    }
}

void RadioScreenView::setPlayVisible(bool visible) {
    radioControlPanel1.setPlayVisible(visible);
}

void RadioScreenView::setStopVisible(bool visible) {
    radioControlPanel1.setStopVisible(visible);
}

void RadioScreenView::fillRadioStationsList(const std::vector<model::Entry>& stations, const uint8_t currentStation){
    for (uint8_t i = 0; i < stations.size(); i++)
    {
        if (currentStation != i) {
            RadioStationsListItems[i].setName(stations[i].getName());
        }
    }
    if (currentStation < stations.size()) {
        RadioStationsSelectedListItems[currentStation].setName(stations[currentStation].getName());
    }
}
