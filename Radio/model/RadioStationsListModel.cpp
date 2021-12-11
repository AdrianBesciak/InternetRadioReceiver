//
// Created by adios on 30.11.2021.
//

#include "RadioStationsListModel.hpp"

namespace model {
    RadioStationsListModel::RadioStationsListModel() {
    }

    const std::vector<Entry>& RadioStationsListModel::getRadioStations() const {
        return radioStations.getEntries();
    }

    uint8_t RadioStationsListModel::getCurrentStationIndex() const {
        return currentStation;
    }
}