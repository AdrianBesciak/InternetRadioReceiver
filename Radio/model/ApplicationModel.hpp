#pragma once
#include <model/PeripheralStateModel.hpp>
#include <model/PlayerModel.h>
#include <model/PlaylistModel.hpp>

namespace model {
    class ApplicationModel {
    public:
        ApplicationModel();

        PeripheralStateModel &getPeripheralStateModel();
        [[nodiscard]] const PeripheralStateModel &getPeripheralStateModel() const;

        PlayerModel &getPlayerModel();
        [[nodiscard]] const PlayerModel &getPlayerModel() const;
    private:
        PeripheralStateModel peripheralStateModel;
        PlayerModel playerModel;
    };
}


