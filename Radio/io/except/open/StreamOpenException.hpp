#pragma once
#include <io/except/IOException.hpp>

namespace io {
    class StreamOpenException : public IOException {
    protected:
        explicit StreamOpenException(const std::string &arg);
    };
}
