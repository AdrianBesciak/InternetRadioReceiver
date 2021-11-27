#pragma once
#include <stdexcept>

namespace audio {
    class AudioPlayerException : public std::runtime_error {
    public:
        explicit AudioPlayerException(const std::string &arg);
    };
}
