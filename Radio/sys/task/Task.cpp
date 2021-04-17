#include "Task.hpp"
#include <sys/Application.hpp>
#include <iostream>

namespace sys::task {
    Task::Task(const std::string &name)
        : name(name) {
        sys::Application::getInstance().addTask(this);
    }

    Task::~Task() = default;

    const std::string &Task::getName() const {
        return name;
    }

    void Task::execute() {
        try {
            executeImpl();
        }
        catch (std::exception &exc) {
            std::cout << "CRITICAL ERROR: " << exc.what() << '\n';
        }
        sys::Application::getInstance().removeTask(this);
        osThreadExit();
    }
}