#include "StreamReadException.hpp"

namespace io {
    StreamReadException::StreamReadException(const std::string &arg)
        : IOException(arg) {}
}
