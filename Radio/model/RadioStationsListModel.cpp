//
// Created by adios on 30.11.2021.
//

#include "RadioStationsListModel.hpp"

namespace model {
    RadioStationsListModel::RadioStationsListModel() {
    }

    std::vector<Entry> RadioStationsListModel::getRadioStations() {
        return radioStations.getEntries();
    }

    Entry RadioStationsListModel::getCurrentStation() {
        return radioStations.getEntries().at(currentStation);
    }
}