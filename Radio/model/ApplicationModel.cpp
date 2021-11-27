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
}
