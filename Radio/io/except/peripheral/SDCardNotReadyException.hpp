#pragma once
#include <io/except/peripheral/PeripheralNotReadyException.hpp>

namespace io {
    class SDCardNotReadyException : public PeripheralNotReadyException {
    public:
        SDCardNotReadyException();
    };
}


