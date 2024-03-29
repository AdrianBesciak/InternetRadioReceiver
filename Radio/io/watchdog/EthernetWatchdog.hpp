#pragma once
#include <functional>
#include <io/watchdog/Watchdog.hpp>

namespace io {
    class EthernetWatchdog : public Watchdog {
    public:
        EthernetWatchdog();
    protected:
        void executeIteration() override;
    };
}
