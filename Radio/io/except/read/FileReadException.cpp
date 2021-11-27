#include "FileReadException.hpp"

namespace io {
    FileReadException::FileReadException(const std::string &arg)
        : StreamReadException(arg) {}
}
