#include "InternalRadioPlaylist.hpp"

namespace audio {
    audio::InternalRadioPlaylist::InternalRadioPlaylist()
            : internalEntries({
              Entry("RMF FM", "http://195.150.20.4/rmf_fm"),
              Entry("RMF MAXX", "http://217.74.72.12/rmf_maxxx"),
              Entry("Eska Bialystok", "http://waw01-02.ic.smcdn.pl:8000/2020-1.mp3"),
              Entry("Radio Poznan", "http://stream4.nadaje.com:8578/poznan"),
              Entry("Radio Warszawa", "http://stream2.technologicznie.net:80/radio_warszawa.mp3"),
              Entry("RDN", "http://stream1.dabcom.pl:8000/rdn_mpl"),
              Entry("Antyradio", "http://redir.atmcdn.pl/sc/o2/Eurozet/live/antyradio.livx?audio=5"),
              Entry("Radio Kielce", "http://gra.radio.kielce.pl:8000/rk2"),
              Entry("Radio Plus Lublin", "http://waw01-02.ic.smcdn.pl:8000/4130-1.mp3")
      }) {}

    const std::vector<Playlist::Entry> &InternalRadioPlaylist::getEntries() const {
        return internalEntries;
    }
}
