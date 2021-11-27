#include "StreamReadException.hpp"

namespace io {
    io::StreamReadException::StreamReadException(const std::string &arg)
        : IOException(arg) {}
}
