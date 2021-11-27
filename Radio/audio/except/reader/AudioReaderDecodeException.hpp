#pragma once
#include <audio/except/reader/AudioReaderException.hpp>

namespace audio {
    class AudioReaderDecodeException : public AudioReaderException {
    public:
        explicit AudioReaderDecodeException(const std::string &arg);
    };
}
