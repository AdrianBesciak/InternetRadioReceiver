#pragma once
#include <io/except/open/StreamOpenException.hpp>

namespace io {
    class FileOpenException : public StreamOpenException {
    public:
        explicit FileOpenException(const std::string &arg);
    };
}
