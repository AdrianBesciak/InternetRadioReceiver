#include "Task.hpp"
#include <sys/Application.hpp>
#include <iostream>

namespace sys {
    Task::Task(const std::string &name)
        : name(name) {
    }

    Task::~Task() = default;



    const std::string &Task::getName() const {
        return name;
    }

    void Task::startTask(TaskPriority priority) {
        sys::Application::getInstance().addTask(this, priority);
    }

    void Task::execute() {
        try {
            executeImpl();
        }
        catch (std::exception &exc) {
            printf("CRITICAL ERROR - %s\r\n", exc.what());
        }
        sys::Application::getInstance().removeTask(this);
        osThreadExit();
    }
}
