#include "IOException.hpp"

namespace io {
    IOException::IOException(const std::string &arg)
        : std::runtime_error(arg) {}
}
