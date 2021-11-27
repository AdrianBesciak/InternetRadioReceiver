#include "HttpReadException.hpp"

namespace io {
    HttpReadException::HttpReadException(const std::string &arg)
        : StreamReadException(arg) {}
}
