#pragma once
#include <list>
#include <memory>
#include <audio/playlist/InternalRadioPlaylist.hpp>
#include <audio/playlist/Playlist.hpp>

namespace model {
    class PlaylistModel {
    public:
        explicit PlaylistModel(const std::shared_ptr<audio::Playlist> &playlist);

        [[nodiscard]] const std::vector<std::string> &getEntries() const;

        [[nodiscard]] bool hasCurrentEntryIndex() const;
        [[nodiscard]] int getCurrentEntryIndex() const;
        void setCurrentEntryIndex(int currentEntryIndex);

    private:
        std::shared_ptr<audio::Playlist> playlist;
        std::vector<std::string> entries;
        int currentEntryIndex;
    };
}
