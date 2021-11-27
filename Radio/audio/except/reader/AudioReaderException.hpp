#pragma once
#include <io/except/IOException.hpp>

namespace audio {
    class AudioReaderException : public io::IOException {
    protected:
        explicit AudioReaderException(const std::string &arg);
    };
}
