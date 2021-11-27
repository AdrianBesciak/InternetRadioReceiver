#include "TaskCreationException.hpp"

namespace sys {
    TaskCreationException::TaskCreationException(const std::string &arg)
        : std::runtime_error(arg) {}
}
