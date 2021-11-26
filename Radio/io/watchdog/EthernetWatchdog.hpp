#pragma once
#include <functional>
#include <sys/task/DelayTask.hpp>

namespace io {
    class EthernetWatchdog : public sys::DelayTask {
    public:
        EthernetWatchdog();
        [[nodiscard]] const std::function<void(bool)> &getOnStateChanged() const;
        void setOnStateChanged(const std::function<void(bool)> &onStateChanged);

    protected:
        void executeIteration() override;
    private:
        std::function<void(bool)> onStateChanged;
        bool oldState;
    };
}
