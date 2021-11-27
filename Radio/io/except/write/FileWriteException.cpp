#include "FileWriteException.hpp"

namespace io {
    FileWriteException::FileWriteException(const std::string &arg)
        : StreamWriteException(arg) {}
}
