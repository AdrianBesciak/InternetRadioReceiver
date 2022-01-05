#pragma once
#include <model/PeripheralStateModel.hpp>
#include <model/PlayerModel.h>
#include <model/PlaylistModel.hpp>
#include <model/ErrorModel.hpp>

namespace model {
    class ApplicationModel {
    public:
        ApplicationModel();

        PeripheralStateModel &getPeripheralStateModel();
        [[nodiscard]] const PeripheralStateModel &getPeripheralStateModel() const;

        PlayerModel &getPlayerModel();
        [[nodiscard]] const PlayerModel &getPlayerModel() const;

        ErrorModel &getErrorModel();
        [[nodiscard]] const ErrorModel &getErrorModel() const;

    private:
        PeripheralStateModel peripheralStateModel;
        PlayerModel playerModel;
        ErrorModel errorModel;
    };
}


