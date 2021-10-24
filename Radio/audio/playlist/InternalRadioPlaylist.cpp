#include "InternalRadioPlaylist.hpp"

namespace audio {
    audio::InternalRadioPlaylist::InternalRadioPlaylist()
            : internalEntries({
              Entry("RMF FM", "http://195.150.20.4/rmf_fm")
            }) {}

    const std::vector<Playlist::Entry> &InternalRadioPlaylist::getEntries() const {
        return internalEntries;
    }
}
