#pragma once
#include <model/PeripheralStateModel.hpp>
#include <model/PlayerModel.hpp>
#include <model/PlaylistModel.hpp>
#include <model/ErrorModel.hpp>

namespace model {
    class ApplicationModel {
    public:
        ApplicationModel(audio::RadioPlaylist &radioPlaylist, audio::SDCardPlaylist &sdCardPlaylist);

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


