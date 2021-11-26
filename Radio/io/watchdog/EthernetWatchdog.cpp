#include "EthernetWatchdog.hpp"
#include <lwip.h>
#include <lwip/prot/dhcp.h>

extern struct netif gnetif;

namespace io {
    EthernetWatchdog::EthernetWatchdog()
        : Watchdog("IRR_EthernetWatchdog") {}

    void EthernetWatchdog::executeIteration() {
        bool newState = false;
        if (netif_is_link_up(&gnetif)) {
            netif_set_up(&gnetif);
            struct dhcp *dhcp = netif_dhcp_data(&gnetif);
            if (dhcp == nullptr || dhcp->state == DHCP_STATE_OFF) {
                dhcp_start(&gnetif);
            }
            else if (dhcp->state == DHCP_STATE_BOUND) {
                newState = true;
            }
        }
        changeState(newState);
    }
}
