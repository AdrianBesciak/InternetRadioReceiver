#include "ApplicationModel.hpp"

namespace model {
    ApplicationModel::ApplicationModel()
        : peripheralStateModel()
        , playerModel()
        , errorModel() {}


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


    ErrorModel &ApplicationModel::getErrorModel() {
        return errorModel;
    }

    const ErrorModel &ApplicationModel::getErrorModel() const {
        return errorModel;
    }
}
