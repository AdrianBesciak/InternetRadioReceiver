#include "FileOpenException.hpp"

namespace io {
    FileOpenException::FileOpenException(const std::string &arg)
        : StreamOpenException(arg) {}
}
