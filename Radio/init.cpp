#include <iostream>
#include <memory>
#include <filesystem/DirectoryListing.hpp>
#include <audio/AudioPlayer.hpp>

extern "C" {
void init() {
    filesystem::DirectoryListing listing("0:/");
    for (auto& file : listing.getFilePaths()) {
        std::cout << file << '\n';
    }
    audio::WavAudioReader *reader = new audio::WavAudioReader("0:/audio44.wav");
    audio::AudioPlayer *player = new audio::AudioPlayer;
    player->setVolume(10);
    player->setSource(reader);
    player->play();
}
}






