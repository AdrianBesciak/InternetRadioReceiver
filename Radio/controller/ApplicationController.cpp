#include "ApplicationController.hpp"
#include <audio/reader/AudioReaderFactory.hpp>
#include <io/stream/file/FileReadStream.hpp>
#include <io/stream/network/HttpStream.hpp>

namespace controller {

    ApplicationController::ApplicationController(audio::AudioPlayer &audioPlayer,
                                                 model::ApplicationModel &applicationModel)
        : volumeController(audioPlayer)
        , errorController(applicationModel.getErrorModel())
        , audioPlayer(audioPlayer)
        , applicationModel(applicationModel) {}

    VolumeController &ApplicationController::getVolumeController() {
        return volumeController;
    }

    ErrorController &ApplicationController::getErrorController() {
        return errorController;
    }

    void ApplicationController::stop() {

    }

    void ApplicationController::pause() {

    }

    void ApplicationController::playPrevious() {

    }

    void ApplicationController::playNext() {

    }

    void ApplicationController::fastForward() {

    }

    void ApplicationController::fastBackward() {

    }

    void ApplicationController::playFromRadio(std::size_t idx) {
        model::PlaylistModel &playlistModel = applicationModel.getPlayerModel().getRadioPlaylist();
        if (idx < playlistModel.getEntryCount()) {
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
            playFromRadio();
        }
    }

    void ApplicationController::playFromSDCard(std::size_t idx) {
        model::PlaylistModel &playlistModel = applicationModel.getPlayerModel().getSdCardPlaylist();
        if (idx < playlistModel.getEntryCount()) {
            playlistModel.setCurrentEntryIndex(static_cast<int>(idx));
            playFromSDCard();
        }
    }

    void ApplicationController::playFromRadio() {
        model::PlaylistModel &playlistModel = applicationModel.getPlayerModel().getRadioPlaylist();
        if (!playlistModel.hasCurrentEntryIndex()) {
            return;
        }
        std::string resource = playlistModel.getCurrentEntry().getResource();
        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>(resource);
        std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
        audioPlayer.setSource(decoder);
        audioPlayer.play();
        applicationModel.getPlayerModel().setMode(model::PlayerModel::Mode::RADIO);
    }

    void ApplicationController::playFromSDCard() {
        model::PlaylistModel &playlistModel = applicationModel.getPlayerModel().getSdCardPlaylist();
        if (!playlistModel.hasCurrentEntryIndex()) {
            return;
        }
        std::string resource = playlistModel.getCurrentEntry().getResource();
        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>(resource);
        std::shared_ptr<audio::AudioReader> decoder = audio::AudioReaderFactory::createReader(readStream);
        audioPlayer.setSource(decoder);
        audioPlayer.play();
        applicationModel.getPlayerModel().setMode(model::PlayerModel::Mode::SD);
    }
}
