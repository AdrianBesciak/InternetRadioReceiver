#include "RadioPlaylist.hpp"

namespace audio {
    audio::RadioPlaylist::RadioPlaylist()
            : internalEntries({

                  //Commented urls don't work when we are updating this list.
                  //To get new urls, you can use https://onlineradiobox.com/ to start playing the music
                  //and extract streams using devtools in your browser.

              Entry("RMF FM", "http://195.150.20.4/rmf_fm"),
              Entry("RMF MAXX", "http://217.74.72.12/rmf_maxxx"),
              //Entry("American Road Radio", "https://c5.radioboss.fm:18224/stream"),
              Entry("Meloradio", "https://n-16-7.dcs.redcdn.pl/sc/o2/Eurozet/live/meloradio.livx?audio=5"),
              //Entry("Radio Zlote Przeboje", "https://pl2-play.adtonos.com/zote-przeboje"),
              //Entry("Eska", "https://radio.stream.smcdn.pl/icradio-p/2380-1.aac/playlist.m3u8"),
              //Entry("Eska Rock", "http://waw01-01.ic.smcdn.pl:8000/5380-1.mp3"),
              Entry("Radio Poznań", "http://stream4.nadaje.com:8578/poznan"),
              Entry("Radio Warszawa", "http://stream2.technologicznie.net:80/radio_warszawa.mp3"),
              Entry("RDN", "http://stream1.dabcom.pl:8000/rdn_mpl"),
              Entry("Antyradio", "http://n-22-14.dcs.redcdn.pl/sc/o2/Eurozet/live/antyradio.livx?audio=5"),
              Entry("Radio Kielce", "http://gra.radio.kielce.pl:8000/rk2"),
              //Entry("Radio Plus Lublin", "http://waw01-02.ic.smcdn.pl:8000/4130-1.mp3"),
              Entry("FOX News Talk", "https://streaming-ent.shoutcast.com/foxnews"),
              Entry("Antenne Bayern", "http://s2-webradio.antenne.de/antenne"),
              Entry("Radio Insomnia", "http://radioinsomnia.ru:8000/radio.mp3"),
              Entry("LightRadio", "http://lightradio.radiostream.pro/mp3"),
              Entry("France Info", "http://icecast.radiofrance.fr/franceinfo-midfi.mp3"),
              Entry("RTVS Radio Slovensko", "https://icecast.stv.livebox.sk/slovensko_128.mp3"),
              Entry("Pioneer FM Moskwa", "http://radio-node-2.dline-media.com/ppr128.mp3")
      }) {}

    const std::vector<Playlist::Entry> &RadioPlaylist::getEntries() const {
        return internalEntries;
    }

    void RadioPlaylist::update() {}
}
