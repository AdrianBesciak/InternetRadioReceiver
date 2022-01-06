#pragma once
#include <audio/playlist/Playlist.hpp>

namespace audio {
    class SDCardPlaylist : public Playlist {
    public:
        SDCardPlaylist();
        [[nodiscard]] const std::vector<Entry> &getEntries() const override;
        void update() final;

    private:
        static std::vector<Entry> readEntries();

        std::vector<Entry> entries;
    };
}
