#pragma once
#include <audio/playlist/Playlist.hpp>

namespace audio {
    class RadioPlaylist : public Playlist {
    public:
        RadioPlaylist();
        [[nodiscard]] const std::vector<Entry> &getEntries() const override;
        void update() final;

    private:
        std::vector<Entry> internalEntries;
    };
}
