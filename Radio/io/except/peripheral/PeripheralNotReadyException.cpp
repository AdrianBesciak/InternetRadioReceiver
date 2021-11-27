#include "PeripheralNotReadyException.hpp"

namespace io {
    PeripheralNotReadyException::PeripheralNotReadyException(const std::string &arg)
        : IOException(arg) {}
}
