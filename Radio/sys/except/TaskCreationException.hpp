#pragma once
#include <stdexcept>

namespace sys {
    class TaskCreationException : public std::runtime_error{
    public:
        explicit TaskCreationException(const std::string &arg);
    };
}
