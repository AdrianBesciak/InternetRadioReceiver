#pragma once
#include <stdexcept>

namespace io {
    class IOException : public std::runtime_error {
    protected:
        explicit IOException(const std::string &arg);
    };
}


