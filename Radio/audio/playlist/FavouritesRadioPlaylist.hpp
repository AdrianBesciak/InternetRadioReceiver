#pragma once
#include <audio/playlist/Playlist.hpp>
#include <audio/playlist/InternalRadioPlaylist.hpp>

namespace audio {
    class FavouritesRadioPlaylist : public Playlist {
    public:
        FavouritesRadioPlaylist();
        [[nodiscard]] const std::vector<Entry> &getEntries() const override;
        void addEntry(std::size_t internalPlaylistIndex);
        void removeEntry(std::size_t favouritesPlaylistIndex);
        
    private:
        void readEntries();
        void writeEntries();
        
        std::vector<Entry> entries;
        InternalRadioPlaylist internalPlaylist;
    };
}
