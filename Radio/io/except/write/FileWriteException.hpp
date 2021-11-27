#pragma once
#include <io/except/write/StreamWriteException.hpp>

namespace io {
    class FileWriteException : public StreamWriteException{
    public:
        explicit FileWriteException(const std::string &arg);
    };
}
