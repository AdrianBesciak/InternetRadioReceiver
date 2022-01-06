#include "SDCardPlaylist.hpp"
#include <filesystem/DirectoryListing.hpp>

namespace audio {
    SDCardPlaylist::SDCardPlaylist()
        : entries() {
        update();
    }

    const std::vector<Playlist::Entry> &SDCardPlaylist::getEntries() const {
        return entries;
    }

    void SDCardPlaylist::update() {
        entries = readEntries();
        notifyUpdated();
    }

    std::vector<Playlist::Entry> SDCardPlaylist::readEntries() {
        try {
            std::vector<Entry> entries;
            filesystem::DirectoryListing listing("0:/audio");
            for (std::size_t i = 0; i < listing.getFileCount(); ++i) {
                const std::string& name = listing.getFileNameAt(i);
                const std::string& path = listing.getFilePathAt(i);
                if (name.size() < 4) {
                    continue;
                }
                std::string extension = name.substr(name.size() - 4);
                if (extension == ".mp3" || extension == ".wav") {
                    entries.emplace_back(name, path);
                }
            }
            return entries;
        }
        catch (std::exception &exc) {
            return {};
        }
    }
}