#include "InvalidAudioFormatException.hpp"

namespace audio {
    InvalidAudioFormatException::InvalidAudioFormatException(const std::string &arg)
        : AudioReaderException(arg) {}
}
