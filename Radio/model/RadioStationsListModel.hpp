#pragma once

#include <list>
#include <audio/playlist/InternalRadioPlaylist.hpp>
#include <audio/playlist/Playlist.hpp>

namespace model {
    using Entry = audio::Playlist::Entry;

    class RadioStationsListModel {
    public:
        RadioStationsListModel();

        const std::vector<Entry> &getRadioStations() const;
        uint8_t getCurrentStationIndex() const;
        void updateCurrentStationIndex(uint8_t i);
    private:
        audio::InternalRadioPlaylist radioStations{};
        uint8_t currentStation{0};
    };
}