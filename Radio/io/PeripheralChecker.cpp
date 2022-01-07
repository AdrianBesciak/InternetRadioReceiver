#include "PeripheralChecker.hpp"
#include <io/except/peripheral/SDCardNotReadyException.hpp>
#include <io/except/peripheral/EthernetNotReadyException.hpp>
#include <ff_gen_drv.h>
#include <lwip/dhcp.h>
#include <lwip/prot/dhcp.h>

extern Disk_drvTypeDef  disk;
extern struct netif gnetif;

namespace io {
    void PeripheralChecker::checkSDCard() {
        if (!disk.is_initialized[0]) {
            throw SDCardNotReadyException();
        }
    }

    void PeripheralChecker::checkEthernet() {
        struct dhcp *dhcp = netif_dhcp_data(&gnetif);
        if (!netif_is_link_up(&gnetif) || !netif_is_up(&gnetif) || dhcp == nullptr || dhcp->state != DHCP_STATE_BOUND) {
            throw EthernetNotReadyException();
        }
    }
}
