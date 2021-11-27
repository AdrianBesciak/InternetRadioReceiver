#include "PlayerModel.h"

namespace model {
    model::PlayerModel::PlayerModel()
            : mode(Mode::NONE)
            , medium()
            , state(audio::AudioPlayer::State::NO_SOURCE)
            , progressCurrent(0.0f)
            , progressTotal(0.0f)
            , volume(100) {}


    PlayerModel::Mode PlayerModel::getMode() const {
        return mode;
    }

    void PlayerModel::setMode(PlayerModel::Mode mode) {
        this->mode = mode;
    }

    const std::string &PlayerModel::getMedium() const {
        return medium;
    }

    void PlayerModel::setMedium(const std::string &media) {
        this->medium = media;
    }

    audio::AudioPlayer::State PlayerModel::getState() const {
        return state;
    }

    void PlayerModel::setState(audio::AudioPlayer::State state) {
        this->state = state;
    }

    float PlayerModel::getProgressCurrent() const {
        return progressCurrent;
    }

    void PlayerModel::setProgressCurrent(float progressCurrent) {
        this->progressCurrent = progressCurrent;
    }

    float PlayerModel::getProgressTotal() const {
        return progressTotal;
    }

    void PlayerModel::setProgressTotal(float progressTotal) {
        this->progressTotal = progressTotal;
    }

    unsigned PlayerModel::getVolume() const {
        return volume;
    }

    void PlayerModel::setVolume(unsigned volume) {
        this->volume = volume;
    }
}
