#include "PlayerSDCardController.hpp"
#include <io/stream/file/FileReadStream.hpp>

namespace controller {
    PlayerSDCardController::PlayerSDCardController(except::ExceptionTranslator &exceptionTranslator,
                                                   audio::AudioPlayer &audioPlayer,
                                                   model::PlayerModel &playerModel)
            : PlayerController(exceptionTranslator,
                               audioPlayer,
                               playerModel,
                               playerModel.getSdCardPlaylist(),
                               model::PlayerModel::Mode::SD) {}


    void PlayerSDCardController::playPrevious() {
        if (playerModel.getMode() == mode) {
            if (playlistModel.hasCurrentEntryIndex()) {
                if (playlistModel.getCurrentEntryIndex() > 0) {
                    playIdx(playlistModel.getCurrentEntryIndex() - 1);
                }
                else {
                    audioPlayer.seek(0.0f);
                    play();
                }
            }
        }
    }

    void PlayerSDCardController::playNext() {
        if (playerModel.getMode() == mode) {
            if (playlistModel.hasCurrentEntryIndex() && playlistModel.getCurrentEntryIndex() < static_cast<int>(playlistModel.getEntryCount()) - 1) {
                playIdx(playlistModel.getCurrentEntryIndex() + 1);
            }
        }
    }

    void PlayerSDCardController::pause() {
        if (playerModel.getMode() == mode) {
            audioPlayer.pause();
        }
    }

    void PlayerSDCardController::fastForward() {
        if (playerModel.getMode() == mode) {
            float seekTime = std::min(audioPlayer.getEndTime(), audioPlayer.getCurrentTime() + 5.0f);
            audioPlayer.seek(seekTime);
        }
    }

    void PlayerSDCardController::fastBackward() {
        if (playerModel.getMode() == mode) {
            float seekTime = std::max(0.0f, audioPlayer.getCurrentTime() - 5.0f);
            audioPlayer.seek(seekTime);
        }
    }


    std::shared_ptr<io::ReadStream> PlayerSDCardController::makeReader(const std::string &source) {
        return std::make_shared<io::FileReadStream>(source);
    }
}
