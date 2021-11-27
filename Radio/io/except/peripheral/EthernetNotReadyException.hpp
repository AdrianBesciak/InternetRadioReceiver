#pragma once
#include <io/except/peripheral/PeripheralNotReadyException.hpp>

namespace io {
    class EthernetNotReadyException : public PeripheralNotReadyException {
    public:
        EthernetNotReadyException();
    };
}


