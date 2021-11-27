#include "ApplicationModule.h"
#include <iostream>
#include <io/stream/network/HttpStream.hpp>
#include <io/stream/file/FileReadStream.hpp>
#include <audio/reader/AudioReaderFactory.hpp>
#include <filesystem/DirectoryListing.hpp>

ApplicationModule* applicationModuleInstance;

ApplicationModule::ApplicationModule()
    : ethernetWatchdog()
    , sdCardWatchdog()
    , audioPlayer()
    , mainDisplay() {
    applicationModuleInstance = this;
    ethernetWatchdog.setOnStateChanged([&](bool state) {
        std::printf("Ethernet state changed to: %d\n", state);
        /*if (stateIndicators) {
            stateIndicators->ethernetStateChanged(state);
        }*/
        if (state) {
            std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>("http://stream4.nadaje.com:15476/radiobialystok");
            std::shared_ptr<audio::AudioReader> audioReader = audio::AudioReaderFactory::createReader(readStream);
            audioPlayer.setSource(audioReader);
            audioPlayer.play();
        }
    });
    sdCardWatchdog.setOnStateChanged([&](bool state) {
        std::printf("SDCard state changed to: %d\n", state);
       /* if (stateIndicators) {
            stateIndicators->sdCardStateChanged(state);
        }*/
    });
    ethernetWatchdog.startTask(sys::TaskPriority::LOW);
    sdCardWatchdog.startTask(sys::TaskPriority::LOW);
    audioPlayer.startTask(sys::TaskPriority::REALTIME);
    mainDisplay.startTask(sys::TaskPriority::LOW);

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
        //std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::FileReadStream>("0:/audio/wav-44.wav");
        //std::shared_ptr<io::ReadStream> readStream = std::make_shared<io::HttpStream>("http://195.150.20.4/rmf_fm");
        //std::shared_ptr<audio::AudioReader> audioReader = std::make_shared<audio::WavAudioReader>(readStream);
        //audioPlayer.setSource(audioReader);
        //audioPlayer.play();
    }
    catch (std::exception &exc) {
        printf("%s\r\n", exc.what());
        std::cout << "Error occurred: " << exc.what() << '\n';
    }
}

bool ApplicationModule::getEthernetState()
{
    return ethernetWatchdog.getState();
}
bool ApplicationModule::getSdCardState()
{
    return sdCardWatchdog.getState();
}

/*
void ApplicationModule::setStateIndicators(controls* indicators)
{
    stateIndicators = indicators;
}*/