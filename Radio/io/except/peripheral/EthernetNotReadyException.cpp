#include "EthernetNotReadyException.hpp"

namespace io {
    EthernetNotReadyException::EthernetNotReadyException()
        : PeripheralNotReadyException("Ethernet not connected") {}
}
