#include "dhcpinit.hpp"
#include <iostream>
#include <lwip.h>
#include <sys/Application.hpp>
using namespace std::literals;

extern struct netif gnetif;

namespace init {
    void initializeDHCP() {
        static bool initialized = false;

        if (!initialized) {
            std::cout << "[INIT] Initializing DHCP\n";

            struct dhcp *dhcp = netif_dhcp_data(&gnetif);
            do {
                sys::Application::wait(50);
            } while (dhcp->state != 0x0A);

            std::cout << "[INIT] Initialized DHCP with IP ("s + ipaddr_ntoa(&gnetif.ip_addr) + ")\n"s;
            initialized = true;
        }
    }
}
