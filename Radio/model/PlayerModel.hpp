#pragma once
#include <string>
#include <audio/AudioPlayer.hpp>
#include <audio/playlist/RadioPlaylist.hpp>
#include <audio/playlist/SDCardPlaylist.hpp>
#include <model/PlaylistModel.hpp>

namespace model {
    class PlayerModel {
    public:
        enum class Mode {
            NONE,
            RADIO,
            SD
        };
        PlayerModel(audio::RadioPlaylist &radioPlaylist, audio::SDCardPlaylist &sdCardPlaylist);

        PlaylistModel& getRadioPlaylist();
        [[nodiscard]] const PlaylistModel &getRadioPlaylist() const;
        PlaylistModel& getSdCardPlaylist();
        [[nodiscard]] const PlaylistModel &getSdCardPlaylist() const;

        [[nodiscard]] Mode getMode() const;
        void setMode(Mode mode);

        [[nodiscard]] audio::AudioPlayer::State getState() const;
        void setState(audio::AudioPlayer::State state);

        void setProgress(float progressCurrent, float progressTotal);

        [[nodiscard]] float getRadioProgressCurrent() const;
        [[nodiscard]] float getRadioProgressTotal() const;
        [[nodiscard]] float getSDCardProgressCurrent() const;
        [[nodiscard]] float getSDCardProgressTotal() const;

        [[nodiscard]] unsigned getVolume() const;
        void setVolume(unsigned volume);

        [[nodiscard]] const std::string& getRadioTitle() const;
        [[nodiscard]] const std::string& getSDCardTitle() const;

    private:
        PlaylistModel radioPlaylist;
        PlaylistModel sdCardPlaylist;

        Mode mode;
        audio::AudioPlayer::State state;
        float progressCurrent;
        float progressTotal;
        unsigned volume;
    };
}


