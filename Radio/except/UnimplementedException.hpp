#pragma once
#include <stdexcept>

namespace except {
    class UnimplementedException : public std::logic_error {
    public:
        UnimplementedException();
    };
}


