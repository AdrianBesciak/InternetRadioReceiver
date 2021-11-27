#include "AudioReaderDecodeException.hpp"

namespace audio {
    AudioReaderDecodeException::AudioReaderDecodeException(const std::string &arg)
        : AudioReaderException(arg) {}
}
