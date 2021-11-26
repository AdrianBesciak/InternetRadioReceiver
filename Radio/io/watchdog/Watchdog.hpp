#pragma once
#include <functional>
#include <sys/task/DelayTask.hpp>

namespace io {
    class Watchdog : public sys::DelayTask {
    public:
        [[nodiscard]] bool getState() const;
        [[nodiscard]] const std::function<void(bool)> &getOnStateChanged() const;
        void setOnStateChanged(const std::function<void(bool)> &onStateChanged);
    protected:
        explicit Watchdog(const std::string &name);
    protected:
        void changeState(bool newState);
    private:
        bool state;
        std::function<void(bool)> onStateChanged;
    };
}
