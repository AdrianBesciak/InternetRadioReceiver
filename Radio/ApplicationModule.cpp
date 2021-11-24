#include "ApplicationModule.h"
#include <iostream>
#include <iomanip>
#include <io/stream/network/HttpStream.hpp>
#include <audio/reader/mpeg/MPEGAudioReader.hpp>
#include <filesystem/DirectoryListing.hpp>
#include <io/stream/file/FileReadStream.hpp>

ApplicationModule::ApplicationModule()
    : audioPlayer()
    , mainDisplay() {
    filesystem::DirectoryListing listing("0:/");
    
    audioPlayer.setOnMediumChanged([](const std::string &medium) {
        std::cout << "[PLAYER] New medium: " << medium << '\n';
    });
    audioPlayer.setOnStateChanged([](audio::AudioPlayer::State state) {
        std::cout << "[PLAYER] State changed: " << static_cast<int>(state) << '\n';
    });
    audioPlayer.setOnVolumeChanged([](std::uint32_t volume) {
        std::cout << "[PLAYER] Volume changed: " << volume << '\n';
    });
//    audioPlayer.setOnProgressChanged([](float current, float total) {
//        std::cout << "[PLAYER] Progress changed: " << std::fixed << std::setprecision(2) << current << '/' << total << '\n';
//    });
    audioPlayer.setVolume(50);


    std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>("0:/file.mp3");
    std::shared_ptr<audio::AudioReader> audioReader = std::make_shared<audio::MPEGAudioReader>(readStream);
    audioPlayer.setSource(audioReader);
    audioPlayer.play();

}
