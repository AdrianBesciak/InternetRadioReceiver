#pragma once
#include <stdexcept>

namespace sys {
    class SingleInstanceException : public std::logic_error {
    public:
        explicit SingleInstanceException(const std::string &arg);
    };
}


