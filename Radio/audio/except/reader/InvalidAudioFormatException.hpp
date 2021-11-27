#pragma once
#include <audio/except/reader/AudioReaderException.hpp>

namespace audio {
    class InvalidAudioFormatException : public AudioReaderException {
    public:
        explicit InvalidAudioFormatException(const std::string &arg);
    };
}


