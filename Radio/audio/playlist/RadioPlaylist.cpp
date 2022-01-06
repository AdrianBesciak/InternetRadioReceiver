#include "RadioPlaylist.hpp"

namespace audio {
    audio::RadioPlaylist::RadioPlaylist()
            : internalEntries({
              Entry("RMF FM", "http://195.150.20.4/rmf_fm"),
              Entry("RMF MAXX", "http://217.74.72.12/rmf_maxxx"),
              Entry("Eska Bialystok", "http://waw01-02.ic.smcdn.pl:8000/2020-1.mp3"),
              Entry("Eska Krakow", "http://waw01-01.ic.smcdn.pl:8000/2070-1.mp3"),
              Entry("Eska Lublin", "http://waw01-01.ic.smcdn.pl:8000/2130-1.mp3"),
              Entry("Eska Radom", "http://waw01-01.ic.smcdn.pl:8000/2210-1.mp3"),
              Entry("Eska Warszawa", "http://waw01-01.ic.smcdn.pl:8000/2380-1.mp3"),
              Entry("Eska Rock", "http://waw01-01.ic.smcdn.pl:8000/5380-1.mp3"),
              Entry("Radio Poznan", "http://stream4.nadaje.com:8578/poznan"),
              Entry("Radio Warszawa", "http://stream2.technologicznie.net:80/radio_warszawa.mp3"),
              Entry("RDN", "http://stream1.dabcom.pl:8000/rdn_mpl"),
              Entry("Antyradio", "http://n-22-14.dcs.redcdn.pl/sc/o2/Eurozet/live/antyradio.livx?audio=5"),
              Entry("Radio Kielce", "http://gra.radio.kielce.pl:8000/rk2"),
              Entry("Radio Plus Lublin", "http://waw01-02.ic.smcdn.pl:8000/4130-1.mp3"),
              Entry("Antenne Bayern", "https://s2-webradio.antenne.de/antenne"),
              Entry("Radio Insomnia", "https://radioinsomnia.ru:8000/radio.mp3"),
              Entry("LightRadio", "https://lightradio.radiostream.pro/mp3"),
              Entry("France Info", "https://icecast.radiofrance.fr/franceinfo-midfi.mp3"), //Fixme działa po przejściu z działających ruskich stacji i tnie po chwili
              Entry("Radio Zlote Przeboje", "https://pl2-play.adtonos.com/zote-przeboje"), //Fixme nie działa i zawiesza GUI
              Entry("Ruskij Rock", "https://rock.amgradio.ru/RusRock"), //Fixme wybór zawiesza GUI
              Entry("Pioneer FM Moskwa", "https://radio-node-2.dline-media.com/ppr128.mp3")   // https://onlineradiobox.com/ru/pioner/?cs=ru.pioner Fixme po chwili zaczyna ciąć
      }) {}

    const std::vector<Playlist::Entry> &RadioPlaylist::getEntries() const {
        return internalEntries;
    }

    void RadioPlaylist::update() {}
}
