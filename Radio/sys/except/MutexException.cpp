#include "MutexException.hpp"

namespace sys {
    MutexException::MutexException(const std::string &arg)
            : runtime_error(arg) {}
}
