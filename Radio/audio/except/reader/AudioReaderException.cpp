#include "AudioReaderException.hpp"

namespace audio {
    AudioReaderException::AudioReaderException(const std::string &arg)
        : io::IOException(arg) {}
}
