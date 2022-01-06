#include "PlayerSDCardController.hpp"
#include <io/stream/file/FileReadStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>

namespace controller {
    PlayerSDCardController::PlayerSDCardController(except::ExceptionTranslator &exceptionTranslator,
                                                   audio::AudioPlayer &audioPlayer,
                                                   model::PlayerModel &playerModel)
            : exceptionTranslator(exceptionTranslator)
            , audioPlayer(audioPlayer)
            , playerModel(playerModel) {}


    void PlayerSDCardController::play() {
        model::PlaylistModel &playlistModel = playerModel.getSdCardPlaylist();
        if (!playlistModel.hasCurrentEntryIndex()) {
            return;
        }
        std::string resource = playlistModel.getCurrentEntry().getResource();
        if (audioPlayer.getSource() == resource) {
            audioPlayer.play();
            return;
        }

        try {
            std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>(resource);
            std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
            audioPlayer.setSource(decoder);
            audioPlayer.play();
            playerModel.setMode(model::PlayerModel::Mode::SD);
        }
        catch (std::exception &exception) {
            exceptionTranslator.translate(exception);
        }
    }

    void PlayerSDCardController::playFromPlaylist(std::size_t idx) {
        model::PlaylistModel &playlistModel = playerModel.getSdCardPlaylist();
        if (idx < playlistModel.getEntryCount()) {
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
            play();
        }
    }

    void PlayerSDCardController::playPrevious() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            model::PlaylistModel &playlistModel = playerModel.getSdCardPlaylist();
            if (playlistModel.hasCurrentEntryIndex()) {
                if (playlistModel.getCurrentEntryIndex() > 0) {
                    playlistModel.setCurrentEntryIndex(playlistModel.getCurrentEntryIndex() - 1);
                }
                else {
                    audioPlayer.seek(0.0f);
                }
                play();
            }
        }
    }

    void PlayerSDCardController::playNext() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            model::PlaylistModel &playlistModel = playerModel.getSdCardPlaylist();
            if (playlistModel.hasCurrentEntryIndex() && playlistModel.getCurrentEntryIndex() < static_cast<int>(playlistModel.getEntryCount()) - 1) {
                playlistModel.setCurrentEntryIndex(playlistModel.getCurrentEntryIndex() + 1);
                play();
            }
        }
    }

    void PlayerSDCardController::pause() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            audioPlayer.pause();
        }
    }

    void PlayerSDCardController::stop() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            audioPlayer.unloadSource();
        }
    }

    void PlayerSDCardController::fastForward() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            float seekTime = std::min(audioPlayer.getEndTime(), audioPlayer.getCurrentTime() + 5.0f);
            audioPlayer.seek(seekTime);
        }
    }

    void PlayerSDCardController::fastBackward() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            float seekTime = std::max(0.0f, audioPlayer.getCurrentTime() - 5.0f);
            audioPlayer.seek(seekTime);
        }
    }
}
