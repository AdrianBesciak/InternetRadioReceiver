#pragma once
#include <io/watchdog/Watchdog.hpp>

namespace io {
    class SDCardWatchdog : public Watchdog {
    public:
        SDCardWatchdog();
    protected:
        void executeIteration() override;
    };
}
