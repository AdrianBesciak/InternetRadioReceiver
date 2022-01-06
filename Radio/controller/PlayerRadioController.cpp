#include <io/stream/network/HttpStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>
#include "PlayerRadioController.hpp"

namespace controller {
    PlayerRadioController::PlayerRadioController(except::ExceptionTranslator &exceptionTranslator,
                                                 audio::AudioPlayer &audioPlayer,
                                                 model::PlayerModel &playerModel)
            : exceptionTranslator(exceptionTranslator)
            , audioPlayer(audioPlayer)
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

        try {
            std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>(resource);
            std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
            audioPlayer.setSource(decoder);
            audioPlayer.play();
            playerModel.setMode(model::PlayerModel::Mode::RADIO);
        }
        catch (std::exception &exception) {
            exceptionTranslator.translate(exception);
        }
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
