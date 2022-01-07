#include "ExceptionTranslator.hpp"
#include <except/UnimplementedException.hpp>
#include <audio/except/player/AudioPlayerException.hpp>
#include <audio/except/reader/AudioReaderDecodeException.hpp>
#include <audio/except/reader/InvalidAudioFormatException.hpp>
#include <io/except/open/FileOpenException.hpp>
#include <io/except/open/HttpOpenException.hpp>
#include <io/except/peripheral/EthernetNotReadyException.hpp>
#include <io/except/peripheral/SDCardNotReadyException.hpp>
#include <io/except/read/FileReadException.hpp>
#include <io/except/read/HttpReadException.hpp>
#include <io/except/write/FileWriteException.hpp>
#include <io/except/write/HttpWriteException.hpp>
#include <cstdio>
#include <memory>
#include <cxxabi.h>

namespace except {

    std::string demangle(const char* name) {
        int status = -4;
        std::unique_ptr<char, void(*)(void*)> res {
                abi::__cxa_demangle(name, nullptr, nullptr, &status),
                std::free
        };
        return (status==0) ? res.get() : name;
    }

    ExceptionTranslator::ExceptionTranslator()
        : onErrorMessage() {}

    void ExceptionTranslator::translate(const std::exception &exception) {
        std::string message = "Unknown error occurred.";
        std::printf("[ExceptionTranslator]: %s(%s)\n", demangle(typeid(exception).name()).c_str(), exception.what());

        if (typeid(exception) == typeid(except::UnimplementedException)) {
            message = "Operation not implemented.";
        }
        else if (typeid(exception) == typeid(audio::AudioPlayerException)) {
            message = "Error occurred in player.";
        }
        else if (typeid(exception) == typeid(audio::AudioReaderDecodeException)) {
            message = "Failed to decode audio.";
        }
        else if (typeid(exception) == typeid(audio::InvalidAudioFormatException)) {
            message = "Unknown audio format.";
        }
        else if (typeid(exception) == typeid(io::FileOpenException)) {
            message = "Failed to open file.";
        }
        else if (typeid(exception) == typeid(io::HttpOpenException)) {
            message = "Failed to open HTTP stream.";
        }
        else if (typeid(exception) == typeid(io::EthernetNotReadyException)) {
            message = "Ethernet is not connected or network connection not established.";
        }
        else if (typeid(exception) == typeid(io::SDCardNotReadyException)) {
            message = "SD card is not connected or mount failed.";
        }
        else if (typeid(exception) == typeid(io::FileReadException)) {
            message = "Failed to read file contents.";
        }
        else if (typeid(exception) == typeid(io::HttpReadException)) {
            message = "Failed to read HTTP stream data.";
        }
        else if (typeid(exception) == typeid(io::FileWriteException)) {
            message = "Failed to write data to file.";
        }
        else if (typeid(exception) == typeid(io::HttpWriteException)) {
            message = "Failed to write data to HTTP stream.";
        }
        else if (typeid(exception) == typeid(std::logic_error)) {
            message = "Program error occurred.";
        }
        else if (typeid(exception) == typeid(std::exception)) {
            message = "Unknown error occurred.";
        }

        if (onErrorMessage != nullptr) {
            onErrorMessage(message);
        }
    }

    const std::function<void(const std::string &)> &ExceptionTranslator::getOnErrorMessage() const {
        return onErrorMessage;
    }

    void ExceptionTranslator::setOnErrorMessage(const std::function<void(const std::string &)> &onErrorMessage) {
        this->onErrorMessage = onErrorMessage;
    }
}
