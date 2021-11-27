#include "StreamOpenException.hpp"

namespace io {
    StreamOpenException::StreamOpenException(const std::string &arg)
        : IOException(arg) {}
}
