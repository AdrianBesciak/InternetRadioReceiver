#include "EthernetWatchdog.hpp"
#include <lwip.h>
#include <lwip/prot/dhcp.h>

extern struct netif gnetif;

namespace io {
    EthernetWatchdog::EthernetWatchdog()
        : sys::DelayTask("IRR_EthernetWatchdog", 100)
        , onStateChanged(nullptr)
        , oldState(false) {

    }

    const std::function<void(bool)> &EthernetWatchdog::getOnStateChanged() const {
        return onStateChanged;
    }

    void EthernetWatchdog::setOnStateChanged(const std::function<void(bool)> &onStateChanged) {
        this->onStateChanged = onStateChanged;
    }

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

        if (oldState != newState) {
            oldState = newState;
            if (onStateChanged != nullptr) {
                onStateChanged(newState);
            }
        }
    }
}
