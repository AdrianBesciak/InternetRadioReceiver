#include <io/stream/network/HttpStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>
#include "PlayerRadioController.hpp"

namespace controller {
    PlayerRadioController::PlayerRadioController(audio::AudioPlayer &audioPlayer, model::PlayerModel &playerModel)
            : audioPlayer(audioPlayer)
            , playerModel(playerModel) {}


    void PlayerRadioController::play() {
        model::PlaylistModel &playlistModel = playerModel.getRadioPlaylist();
        if (!playlistModel.hasCurrentEntryIndex()) {
            return;
        }
        std::string resource = playlistModel.getCurrentEntry().getResource();
        if (audioPlayer.getSource() == resource) {
            audioPlayer.play();
            return;
        }

        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>(resource);
        std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
        audioPlayer.setSource(decoder);
        audioPlayer.play();
        playerModel.setMode(model::PlayerModel::Mode::RADIO);
    }

    void PlayerRadioController::playFromPlaylist(std::size_t idx) {
        model::PlaylistModel &playlistModel = playerModel.getRadioPlaylist();
        if (idx < playlistModel.getEntryCount()) {
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
            play();
        }
    }

    void PlayerRadioController::stop() {
        if (playerModel.getMode() == model::PlayerModel::Mode::RADIO) {
            audioPlayer.unloadSource();
        }
    }
}
