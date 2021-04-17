#include "DelayTask.hpp"
#include <cmsis_os.h>

namespace sys::task {
    DelayTask::DelayTask(const std::string &name, std::uint32_t delay)
    : Task(name)
    , delay(delay) {}

    std::uint32_t DelayTask::getDelay() const {
        return delay;
    }

    void DelayTask::executeImpl() {
        while (true) {
            executeIteration();
            osDelay(delay);
        }
    }
}