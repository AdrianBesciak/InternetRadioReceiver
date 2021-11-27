#pragma once
#include <io/except/read/StreamReadException.hpp>

namespace io {
    class HttpReadException : public StreamReadException {
    public:
        explicit HttpReadException(const std::string &arg);
    };
}


