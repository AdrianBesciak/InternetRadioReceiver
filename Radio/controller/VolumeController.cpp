#include "VolumeController.hpp"

namespace controller {
    VolumeController::VolumeController(audio::AudioPlayer &audioPlayer)
        : audioPlayer(audioPlayer) {}

    void VolumeController::increaseVolume() {
        auto volume = audioPlayer.getVolume();
        if (audioPlayer.getVolume() > 95) {
            setVolume(100);
        }
        else {
            setVolume(volume + 5);
        }
    }

    void VolumeController::decreaseVolume() {
        auto volume = audioPlayer.getVolume();
        if (audioPlayer.getVolume() > 5) {
            setVolume(volume - 5);
        }
        else {
            setVolume(0);
        }
    }

    void VolumeController::setVolume(std::uint32_t volume) {
        audioPlayer.setVolume(volume);
    }
}
