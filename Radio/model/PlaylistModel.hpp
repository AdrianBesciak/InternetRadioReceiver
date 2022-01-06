#pragma once
#include <list>
#include <memory>
#include <audio/playlist/Playlist.hpp>

namespace model {
    class PlaylistModel {
    public:
        explicit PlaylistModel(audio::Playlist& playlist);

        [[nodiscard]] const std::vector<std::string> &getTitles() const;
        [[nodiscard]] const std::string& getCurrentTitle() const;

        [[nodiscard]] const std::vector<audio::Playlist::Entry>& getEntries();
        [[nodiscard]] const audio::Playlist::Entry& getCurrentEntry() const;

        [[nodiscard]] std::size_t getEntryCount() const;

        [[nodiscard]] bool hasCurrentEntryIndex() const;
        [[nodiscard]] int getCurrentEntryIndex() const;
        void setCurrentEntryIndex(int currentEntryIndex);

    private:
        void updateTitles();

        audio::Playlist& playlist;
        std::vector<std::string> titles;
        int currentEntryIndex;
    };
}
