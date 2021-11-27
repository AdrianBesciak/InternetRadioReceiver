#pragma once
#include <io/except/read/StreamReadException.hpp>

namespace io {
    class FileReadException : public StreamReadException {
    public:
        explicit FileReadException(const std::string &arg);
    };
}
