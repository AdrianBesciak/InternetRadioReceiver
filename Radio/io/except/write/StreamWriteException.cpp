#include "StreamWriteException.hpp"

namespace io {
    StreamWriteException::StreamWriteException(const std::string &arg)
        : IOException(arg) {}
}
