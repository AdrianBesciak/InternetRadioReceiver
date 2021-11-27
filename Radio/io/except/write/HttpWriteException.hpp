#pragma once
#include <io/except/write/StreamWriteException.hpp>

namespace io {
    class HttpWriteException : public StreamWriteException {
    public:
        explicit HttpWriteException(const std::string &arg);
    };
}


