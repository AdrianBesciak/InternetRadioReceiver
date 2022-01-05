#include "PlayerVolumeController.hpp"

namespace controller {
    PlayerVolumeController::PlayerVolumeController(audio::AudioPlayer &audioPlayer)
        : audioPlayer(audioPlayer) {}

    void PlayerVolumeController::increaseVolume() {
        auto volume = audioPlayer.getVolume();
        if (audioPlayer.getVolume() > 95) {
            setVolume(100);
        }
        else {
            setVolume(volume + 5);
        }
    }

    void PlayerVolumeController::decreaseVolume() {
        auto volume = audioPlayer.getVolume();
        if (audioPlayer.getVolume() > 5) {
            setVolume(volume - 5);
        }
        else {
            setVolume(0);
        }
    }

    void PlayerVolumeController::setVolume(std::uint32_t volume) {
        audioPlayer.setVolume(volume);
    }
}
