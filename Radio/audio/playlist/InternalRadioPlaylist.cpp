#include "InternalRadioPlaylist.hpp"

namespace audio {
    audio::InternalRadioPlaylist::InternalRadioPlaylist()
            : internalEntries({
              Entry("RMF FM", "http://195.150.20.4/rmf_fm"),
              Entry("RMF MAXX", "http://195.150.20.4/rmf_fm"),
              Entry("Eska", "http://195.150.20.4/rmf_fm"),
              Entry("Radio Krakow", "http://195.150.20.4/rmf_fm"),
              Entry("Radio Maryja", "http://195.150.20.4/rmf_fm"),
              Entry("RDN", "http://195.150.20.4/rmf_fm"),
              Entry("Radio ZET", "http://195.150.20.4/rmf_fm"),
              Entry("Radio 357", "http://195.150.20.4/rmf_fm"),
              Entry("MINE", "http://195.150.20.4/rmf_fm")
            }) {}

    const std::vector<Playlist::Entry> &InternalRadioPlaylist::getEntries() const {
        return internalEntries;
    }
}
