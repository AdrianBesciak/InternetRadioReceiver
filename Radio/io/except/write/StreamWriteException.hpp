#pragma once
#include <io/except/IOException.hpp>

namespace io {
    class StreamWriteException : public IOException {
    public:
        explicit StreamWriteException(const std::string &arg);
    };
}
