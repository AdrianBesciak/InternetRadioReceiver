#include <iostream>
#include <iomanip>
#include <memory>
#include <audio/AudioPlayer.hpp>
#include <audio/reader/wav/WavAudioReader.hpp>
#include <filesystem/DirectoryListing.hpp>
#include <io/stream/file/FileReadStream.hpp>
#include <io/stream/network/HttpStream.hpp>
#include <audio/reader/mpeg/MPEGAudioReader.hpp>

extern "C" {
void init() {
    try {
        /*std::shared_ptr<io::ReadStream> stream = std::make_shared<io::FileReadStream>("0:/sample4.mp3");
        test2(stream);
         */


        audio::AudioPlayer *player = new audio::AudioPlayer;
        std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>("0:/sample4.mp3");
        std::shared_ptr<audio::AudioReader> audioReader = std::make_shared<audio::MPEGAudioReader>(readStream);

        player->setOnMediumChanged([](const std::string &medium) {
            std::cout << "[PLAYER] New medium: " << medium << '\n';
        });
        player->setOnStateChanged([](audio::AudioPlayer::State state) {
            std::cout << "[PLAYER] State changed: " << static_cast<int>(state) << '\n';
        });
        player->setOnVolumeChanged([](std::uint32_t volume) {
            std::cout << "[PLAYER] Volume changed: " << volume << '\n';
        });
        /*player->setOnProgressChanged([player](float current, float total) {
            std::cout << "[PLAYER] Progress changed: " << std::fixed << std::setprecision(2) << current << '/' << total << '\n';
        });*/

        player->setVolume(50);
        player->setSource(audioReader);
        player->play();
    }
    catch (std::exception &exc) {
        std::cout << "Error occurred: " << exc.what() << '\n';
    }
}
}






