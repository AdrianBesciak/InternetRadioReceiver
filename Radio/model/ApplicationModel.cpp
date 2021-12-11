#include "ApplicationModel.hpp"

namespace model {
    ApplicationModel::ApplicationModel()
        : peripheralStateModel() {}


    PeripheralStateModel &ApplicationModel::getPeripheralStateModel() {
        return peripheralStateModel;
    }

    const PeripheralStateModel &ApplicationModel::getPeripheralStateModel() const {
        return peripheralStateModel;
    }


    PlayerModel &ApplicationModel::getPlayerModel() {
        return playerModel;
    }

    const PlayerModel &ApplicationModel::getPlayerModel() const {
        return playerModel;
    }

    RadioStationsListModel &ApplicationModel::getRadioStationsListModel() {
        return radioStationsListModel;
    }

    const RadioStationsListModel &ApplicationModel::getRadioStationsListModel() const {
        return radioStationsListModel;
    }
}
