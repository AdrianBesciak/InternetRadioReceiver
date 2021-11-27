#pragma once
#include <io/except/IOException.hpp>


namespace io {
    class PeripheralNotReadyException : public IOException {
    protected:
        explicit PeripheralNotReadyException(const std::string &arg);
    };
}


