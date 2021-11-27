#include "HttpWriteException.hpp"

namespace io {
    HttpWriteException::HttpWriteException(const std::string &arg)
        : StreamWriteException(arg) {}
}
