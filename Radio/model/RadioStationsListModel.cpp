//
// Created by adios on 30.11.2021.
//

#include "RadioStationsListModel.hpp"
#include <stdexcept>

namespace model {
    RadioStationsListModel::RadioStationsListModel() {
    }

    const std::vector<Entry>& RadioStationsListModel::getRadioStations() const {
        return radioStations.getEntries();
    }

    uint8_t RadioStationsListModel::getCurrentStationIndex() const {
        return currentStation;
    }

    void RadioStationsListModel::updateCurrentStationIndex(uint8_t i) {
        if (i < getRadioStations().size()) {
            currentStation = i;
        } else {
            throw std::out_of_range("Current station index higher than radio stations amount");
        }
    }
}