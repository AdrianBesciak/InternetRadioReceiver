#pragma once
#include <io/except/IOException.hpp>

namespace io {
    class StreamReadException : public IOException{
    protected:
        explicit StreamReadException(const std::string &arg);
    };
}


