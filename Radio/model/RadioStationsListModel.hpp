#pragma once

#include <list>
#include <audio/playlist/InternalRadioPlaylist.hpp>
#include <audio/playlist/Playlist.hpp>

namespace model {
    class RadioStationsListModel {
    public:
        using Entry = audio::Playlist::Entry;
        RadioStationsListModel();
        [[nodiscard]] const std::vector<Entry> &getRadioStations() const;
        [[nodiscard]] std::uint8_t getCurrentStationIndex() const;
        void updateCurrentStationIndex(std::uint8_t i);
    private:
        audio::InternalRadioPlaylist radioStations;
        std::uint8_t currentStation;
    };
}
