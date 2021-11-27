#pragma once
#include <string>
#include <audio/AudioPlayer.hpp>

namespace model {
    class PlayerModel {
    public:
        enum class Mode {
            NONE,
            RADIO,
            SD
        };

        PlayerModel();

        [[nodiscard]] Mode getMode() const;
        void setMode(Mode mode);

        [[nodiscard]] const std::string &getMedium() const;
        void setMedium(const std::string &media);

        [[nodiscard]] audio::AudioPlayer::State getState() const;
        void setState(audio::AudioPlayer::State state);

        [[nodiscard]] float getProgressCurrent() const;
        void setProgressCurrent(float progressCurrent);

        [[nodiscard]] float getProgressTotal() const;
        void setProgressTotal(float progressTotal);

        [[nodiscard]] unsigned getVolume() const;
        void setVolume(unsigned volume);

    private:
        Mode mode;
        std::string medium;
        audio::AudioPlayer::State state;
        float progressCurrent;
        float progressTotal;
        unsigned volume;
    };
}


