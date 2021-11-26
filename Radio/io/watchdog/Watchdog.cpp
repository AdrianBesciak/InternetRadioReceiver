#include "Watchdog.hpp"

namespace io {
    bool Watchdog::getState() const {
        return state;
    }

    const std::function<void(bool)> &Watchdog::getOnStateChanged() const {
        return onStateChanged;
    }

    void Watchdog::setOnStateChanged(const std::function<void(bool)> &onStateChanged) {
        this->onStateChanged = onStateChanged;
    }

    Watchdog::Watchdog(const std::string &name)
        : sys::DelayTask(name, 100)
        , state(false) {}

    void Watchdog::changeState(bool newState) {
        if (newState != state) {
            state = newState;
            if (onStateChanged != nullptr) {
                onStateChanged(state);
            }
        }
    }
}
