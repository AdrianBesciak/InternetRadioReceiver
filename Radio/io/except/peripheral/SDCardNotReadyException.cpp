#include "SDCardNotReadyException.hpp"

namespace io {
    SDCardNotReadyException::SDCardNotReadyException()
        : PeripheralNotReadyException("SDCard not connected"){}
}
