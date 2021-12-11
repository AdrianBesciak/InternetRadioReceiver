#pragma once
#include <model/PeripheralStateModel.hpp>
#include <model/PlayerModel.h>
#include <model/RadioStationsListModel.hpp>

namespace model {
    class ApplicationModel {
    public:
        ApplicationModel();

        PeripheralStateModel &getPeripheralStateModel();
        [[nodiscard]] const PeripheralStateModel &getPeripheralStateModel() const;

        PlayerModel &getPlayerModel();
        [[nodiscard]] const PlayerModel &getPlayerModel() const;

        RadioStationsListModel &getRadioStationsListModel();
        [[nodiscard]] const RadioStationsListModel &getRadioStationsListModel() const;
    private:
        PeripheralStateModel peripheralStateModel;
        PlayerModel playerModel;
        RadioStationsListModel radioStationsListModel;
    };
}


