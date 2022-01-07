#pragma once
#include <except/ExceptionTranslator.hpp>
#include <audio/AudioPlayer.hpp>
#include <model/PlayerModel.hpp>

namespace controller {
    class PlayerController {
    public:
        void play();
        void playFromPlaylist(std::size_t idx);
        void stop();

    protected:
        PlayerController(except::ExceptionTranslator &exceptionTranslator,
                         audio::AudioPlayer &audioPlayer,
                         model::PlayerModel &playerModel,
                         model::PlaylistModel &playlistModel,
                         model::PlayerModel::Mode mode);

        void playIdx(std::size_t idx);
        virtual std::shared_ptr<io::ReadStream> makeReader(const std::string& source) = 0;

        except::ExceptionTranslator& exceptionTranslator;
        audio::AudioPlayer& audioPlayer;
        model::PlayerModel& playerModel;
        model::PlaylistModel& playlistModel;
        model::PlayerModel::Mode mode;
    };
}


