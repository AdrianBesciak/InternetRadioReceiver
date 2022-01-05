#include "PlayerSDCardController.hpp"
#include <io/stream/file/FileReadStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>

namespace controller {
    PlayerSDCardController::PlayerSDCardController(audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel)
            : audioPlayer(audioPlayer)
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

        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>(resource);
        std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
        audioPlayer.setSource(decoder);
        audioPlayer.play();
        playerModel.setMode(model::PlayerModel::Mode::SD);
    }

    void PlayerSDCardController::playFromPlaylist(std::size_t idx) {
        model::PlaylistModel &playlistModel = playerModel.getSdCardPlaylist();
        if (idx < playlistModel.getEntryCount()) {
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
            play();
        }
    }

    void PlayerSDCardController::playPrevious() {

    }

    void PlayerSDCardController::playNext() {

    }

    void PlayerSDCardController::pause() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            audioPlayer.pause();
        }
    }

    void PlayerSDCardController::stop() {
        if (playerModel.getMode() == model::PlayerModel::Mode::SD) {
            audioPlayer.stop();
        }
    }

    void PlayerSDCardController::fastForward() {

    }

    void PlayerSDCardController::fastBackward() {

    }
}
