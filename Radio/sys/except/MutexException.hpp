#pragma once
#include <stdexcept>

namespace sys {
    class MutexException : public std::runtime_error {
    public:
        explicit MutexException(const std::string &arg);
    };
}

