#pragma once
#include <audio/playlist/Playlist.hpp>

namespace audio {
    class InternalRadioPlaylist : public Playlist {
    public:
        InternalRadioPlaylist();
        [[nodiscard]] const std::vector<Entry> &getEntries() const override;
        
    private:
        std::vector<Entry> internalEntries;
    };
}
