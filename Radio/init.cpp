#include <iostream>
#include <filesystem/DirectoryListing.hpp>
#include <audio/AudioPlayer.hpp>

extern "C" {
void init() {
    audio::AudioPlayer *player = new audio::AudioPlayer;
    player->setVolume(50);
    player->setSource("0:/audio8.wav");
    player->play();
}
}






