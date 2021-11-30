#pragma once

#include <list>
#include <audio/playlist/FavouritesRadioPlaylist.hpp>
#include <audio/playlist/Playlist.hpp>

namespace model {
    using Entry = audio::Playlist::Entry;

    class RadioStationsListModel {
    public:
        RadioStationsListModel();

        std::vector<Entry> getRadioStations();
        Entry getCurrentStation();
    private:
        audio::FavouritesRadioPlaylist radioStations;
        unsigned int currentStation{0};
    };
}