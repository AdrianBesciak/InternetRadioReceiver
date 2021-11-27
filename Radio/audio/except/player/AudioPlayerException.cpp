#include "AudioPlayerException.hpp"

namespace audio {
    AudioPlayerException::AudioPlayerException(const std::string &arg)
        : std::runtime_error(arg) {}
}
