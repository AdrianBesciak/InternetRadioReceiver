#include "PlayerModel.h"

namespace model {
    model::PlayerModel::PlayerModel()
            : radioPlaylist(std::make_shared<audio::InternalRadioPlaylist>())
            , sdCardPlaylist(std::make_shared<audio::InternalRadioPlaylist>())
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


    void PlayerModel::setProgressCurrent(float progressCurrent) {
        this->progressCurrent = progressCurrent;
    }

    void PlayerModel::setProgressTotal(float progressTotal) {
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
        if (mode == Mode::RADIO && radioPlaylist.hasCurrentEntryIndex()) {
            return radioPlaylist.getEntries()[radioPlaylist.getCurrentEntryIndex()];
        }
        return EMPTY;
    }

    const std::string &PlayerModel::getSDCardTitle() const {
        static std::string EMPTY = "No file selected";
        if (mode == Mode::SD && sdCardPlaylist.hasCurrentEntryIndex()) {
            return sdCardPlaylist.getEntries()[sdCardPlaylist.getCurrentEntryIndex()];
        }
        return EMPTY;
    }
}
