#include "HttpOpenException.hpp"

namespace io {
    HttpOpenException::HttpOpenException(const std::string &arg)
        : StreamOpenException(arg) {}
}
