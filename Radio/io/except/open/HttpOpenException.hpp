#pragma once
#include <io/except/open/StreamOpenException.hpp>

namespace io {
    class HttpOpenException : public StreamOpenException {
    public:
        explicit HttpOpenException(const std::string &arg);
    };
}
