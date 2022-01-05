#include "PlaylistModel.hpp"
#include <stdexcept>
#include <algorithm>

namespace model {
    PlaylistModel::PlaylistModel(const std::shared_ptr<audio::Playlist> &playlist)
        : playlist(playlist)
        , entries(playlist->getEntries().size())
        , currentEntryIndex(-1) {
        std::transform(playlist->getEntries().begin(), playlist->getEntries().end(), entries.begin(), [](auto &entry) {return entry.getName();});
    }

    const std::vector<std::string>& PlaylistModel::getEntries() const {
        return entries;
    }

    bool PlaylistModel::hasCurrentEntryIndex() const {
        return currentEntryIndex != -1;
    }

    int PlaylistModel::getCurrentEntryIndex() const {
        return currentEntryIndex;
    }

    void PlaylistModel::setCurrentEntryIndex(int currentEntryIndex) {
        if (static_cast<std::uint32_t>(currentEntryIndex) >= getEntries().size() || currentEntryIndex != -1) {
            throw std::out_of_range("Current entry index invalid (" + std::to_string(currentEntryIndex) + "/" + std::to_string(this->currentEntryIndex) + ")");
        }
        this->currentEntryIndex = currentEntryIndex;
    }
}
