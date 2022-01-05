#include "PlaylistModel.hpp"
#include <stdexcept>
#include <algorithm>

namespace model {
    PlaylistModel::PlaylistModel(const std::shared_ptr<audio::Playlist> &playlist)
        : playlist(playlist)
        , titles(playlist->getEntries().size())
        , currentEntryIndex(-1) {
        std::transform(playlist->getEntries().begin(), playlist->getEntries().end(), titles.begin(), [](auto &entry) {return entry.getName();});
    }


    const std::vector<std::string>& PlaylistModel::getTitles() const {
        return titles;
    }

    const std::string &PlaylistModel::getCurrentTitle() const {
        if (!hasCurrentEntryIndex()) {
            throw std::logic_error("Current entry not selected");
        }
        return titles[currentEntryIndex];
    }


    const std::vector<audio::Playlist::Entry>& PlaylistModel::getEntries() {
        return playlist->getEntries();
    }

    const audio::Playlist::Entry &PlaylistModel::getCurrentEntry() const {
        if (!hasCurrentEntryIndex()) {
            throw std::logic_error("Current entry not selected");
        }
        return playlist->getEntries()[currentEntryIndex];
    }


    std::size_t PlaylistModel::getEntryCount() const {
        return titles.size();
    }


    bool PlaylistModel::hasCurrentEntryIndex() const {
        return currentEntryIndex != -1;
    }

    int PlaylistModel::getCurrentEntryIndex() const {
        return currentEntryIndex;
    }

    void PlaylistModel::setCurrentEntryIndex(int currentEntryIndex) {
        if (static_cast<std::uint32_t>(currentEntryIndex) >= getTitles().size() && currentEntryIndex != -1) {
            throw std::out_of_range("Current entry index invalid (" + std::to_string(currentEntryIndex) + "/" + std::to_string(getTitles().size()) + ")");
        }
        this->currentEntryIndex = currentEntryIndex;
    }
}
