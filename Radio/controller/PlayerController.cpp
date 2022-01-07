#include "PlayerController.hpp"
#include <audio/reader/AudioReaderFactory.hpp>

namespace controller {
    void PlayerController::play() {
        if (playlistModel.hasCurrentEntryIndex()) {
            playIdx(playlistModel.getCurrentEntryIndex());
        }
    }

    void PlayerController::playFromPlaylist(std::size_t idx) {
        if (idx < playlistModel.getEntryCount()) {
            playIdx(idx);
        }
    }

    void PlayerController::stop() {
        if (playerModel.getMode() == mode) {
            audioPlayer.unloadSource();
        }
    }


    PlayerController::PlayerController(except::ExceptionTranslator &exceptionTranslator,
                                       audio::AudioPlayer &audioPlayer,
                                       model::PlayerModel &playerModel,
                                       model::PlaylistModel &playlistModel,
                                       model::PlayerModel::Mode mode)
            : exceptionTranslator(exceptionTranslator), audioPlayer(audioPlayer), playerModel(playerModel),
              playlistModel(playlistModel), mode(mode) {}


    void PlayerController::playIdx(std::size_t idx) {
        if (idx >= playlistModel.getEntryCount()) {
            return;
        }

        std::string resource = playlistModel.getEntries()[idx].getResource();
        if (audioPlayer.getSource() == resource) {
            audioPlayer.play();
            return;
        }

        try {
            std::shared_ptr<io::ReadStream> readStream = makeReader(resource);
            std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
            audioPlayer.setSource(decoder);
            audioPlayer.play();
            playerModel.setMode(mode);
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
        }
        catch (std::exception &exception) {
            exceptionTranslator.translate(exception);
        }
    }
}
