#include "PlayerModel.hpp"

namespace model {
    model::PlayerModel::PlayerModel(audio::RadioPlaylist &radioPlaylist, audio::SDCardPlaylist &sdCardPlaylist)
            : radioPlaylist(radioPlaylist)
            , sdCardPlaylist(sdCardPlaylist)
            , mode(Mode::NONE)
            , state(audio::AudioPlayer::State::NO_SOURCE)
            , progressCurrent(0.0f)
            , progressTotal(0.0f)
            , volume(100) {}


    PlaylistModel &PlayerModel::getRadioPlaylist() {
        return radioPlaylist;
    }

    const PlaylistModel &PlayerModel::getRadioPlaylist() const {
        return radioPlaylist;
    }

    PlaylistModel &PlayerModel::getSdCardPlaylist() {
        return sdCardPlaylist;
    }

    const PlaylistModel &PlayerModel::getSdCardPlaylist() const {
        return sdCardPlaylist;
    }


    PlayerModel::Mode PlayerModel::getMode() const {
        return mode;
    }

    void PlayerModel::setMode(PlayerModel::Mode mode) {
        this->mode = mode;
    }


    audio::AudioPlayer::State PlayerModel::getState() const {
        return state;
    }

    void PlayerModel::setState(audio::AudioPlayer::State state) {
        this->state = state;
    }


    void PlayerModel::setProgress(float progressCurrent, float progressTotal) {
        this->progressCurrent = progressCurrent;
        this->progressTotal = progressTotal;
    }


    float PlayerModel::getRadioProgressCurrent() const {
        if (mode == Mode::RADIO) {
            return progressCurrent;
        }
        return 0.0f;
    }

    float PlayerModel::getRadioProgressTotal() const {
        if (mode == Mode::RADIO) {
            return progressTotal;
        }
        return 0.0f;
    }

    float PlayerModel::getSDCardProgressCurrent() const {
        if (mode == Mode::SD) {
            return progressCurrent;
        }
        return 0.0f;
    }

    float PlayerModel::getSDCardProgressTotal() const {
        if (mode == Mode::SD) {
            return progressTotal;
        }
        return 0.0f;

    }


    unsigned PlayerModel::getVolume() const {
        return volume;
    }

    void PlayerModel::setVolume(unsigned volume) {
        this->volume = volume;
    }

    const std::string& PlayerModel::getRadioTitle() const {
        static std::string EMPTY = "No station selected";
        if (radioPlaylist.hasCurrentEntryIndex()) {
            return radioPlaylist.getTitles()[radioPlaylist.getCurrentEntryIndex()];
        }
        return EMPTY;
    }

    const std::string &PlayerModel::getSDCardTitle() const {
        static std::string EMPTY = "No file selected";
        if (sdCardPlaylist.hasCurrentEntryIndex()) {
            return sdCardPlaylist.getTitles()[sdCardPlaylist.getCurrentEntryIndex()];
        }
        return EMPTY;
    }
}
