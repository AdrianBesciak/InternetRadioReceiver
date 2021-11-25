#include "ApplicationModule.h"
#include <iostream>
#include <io/stream/network/HttpStream.hpp>
#include <audio/reader/mpeg/MPEGAudioReader.hpp>
#include <audio/reader/wav//WavAudioReader.hpp>
#include <audio/playlist/FavouritesRadioPlaylist.hpp>
#include <filesystem/DirectoryListing.hpp>
#include <io/stream/file/FileReadStream.hpp>

ApplicationModule::ApplicationModule()
    : audioPlayer()
    , mainDisplay() {
    audioPlayer.startTask(sys::TaskPriority::REALTIME);
    mainDisplay.startTask(sys::TaskPriority::LOW);
    auto listing = filesystem::DirectoryListing("0:/audio");
    audio::FavouritesRadioPlaylist playlist;
    playlist.addEntry(0);
    playlist.removeEntry(0);
    playlist.addEntry(0);

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
    audioPlayer.setVolume(25);

    try {
        //std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>("0:/audio/mp3-44-320-2.mp3");
        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>("0:/audio/wav-44.wav");
        //std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>("http://195.150.20.4/rmf_fm");
        std::shared_ptr<audio::AudioReader> audioReader = std::make_shared<audio::WavAudioReader>(readStream);
        audioPlayer.setSource(audioReader);
        audioPlayer.play();
    }
    catch (std::exception &exc) {
        printf("%s\r\n", exc.what());
        std::cout << "Error occurred: " << exc.what() << '\n';
    }
}
