#include "FavouritesRadioPlaylist.hpp"
#include <stdexcept>
#include <algorithm>
#include <map>
#include <io/stream/file/FileReadStream.hpp>
#include <io/stream/file/FileWriteStream.hpp>

namespace audio {
    static const std::string PLAYLIST_PATH = "0:/favs.txt";
    
    FavouritesRadioPlaylist::FavouritesRadioPlaylist()
        : entries()
        , internalPlaylist() {
        readEntries();
    }

    const std::vector<Playlist::Entry> &FavouritesRadioPlaylist::getEntries() const {
        return entries;
    }

    void FavouritesRadioPlaylist::addEntry(std::size_t internalPlaylistIndex) {
        const std::vector<Entry>& internalEntries = internalPlaylist.getEntries();
        if (internalPlaylistIndex > internalEntries.size()) {
            throw std::invalid_argument("internalPlaylistIndex is invalid");
        }
        const Entry& internalEntry = internalEntries[internalPlaylistIndex];
        auto it = std::find_if(entries.begin(), entries.end(),
                            [&internalEntry](Entry &entry) { return entry.getName() == internalEntry.getName(); }
                            );
        if (it != entries.end()) {
            return;
        }
        entries.push_back(internalEntry);
        writeEntries();
    }

    void FavouritesRadioPlaylist::removeEntry(std::size_t favouritesPlaylistIndex) {
        if (favouritesPlaylistIndex > entries.size()) {
            throw std::invalid_argument("favouritesPlaylistIndex is invalid");
        }
        entries.erase(entries.begin() + static_cast<std::vector<Entry>::difference_type>(favouritesPlaylistIndex));
        writeEntries();
    }

    void FavouritesRadioPlaylist::readEntries() {
        const std::vector<Entry>& internalEntries = internalPlaylist.getEntries();
        std::unordered_map<std::string, std::string> internalEntryMap;
        for (auto &entry : internalEntries) {
            internalEntryMap.insert({entry.getName(), entry.getResource()});
        }
        io::FileReadStream stream(PLAYLIST_PATH, true);
        while (stream.hasNext()) {
            std::string line = stream.readLine();
            auto it = internalEntryMap.find(line);
            if (it != internalEntryMap.end()) {
                entries.emplace_back(it->first, it->second);
            }
        }
    }

    void FavouritesRadioPlaylist::writeEntries() {
        io::FileWriteStream writeStream(PLAYLIST_PATH);
        for (auto &entry : entries) {
            writeStream.writeLine(entry.getName());
        }
    }
}
