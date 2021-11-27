#include "Application.hpp"
#include <stdexcept>
#include <cmsis_os.h>
#include <sys/task/Task.hpp>
#include <sys/except/TaskCreationException.hpp>

namespace sys {
    void taskEntrypoint(void *arg) {
        const std::string name = *reinterpret_cast<std::string*>(arg);
        sys::Application& app = sys::Application::getInstance();
        app.taskMap[name]->execute();
    }

    Application* Application::application = nullptr;

    Application::Application()
            : taskMap() {}

    Application &sys::Application::getInstance() {
        if (application == nullptr) {
            application = new Application;
        }
        return *application;
    }

    void Application::wait(std::uint32_t ticks) {
        vTaskDelay(ticks);
    }

    void Application::addTask(Task *task, TaskPriority priority) {
        taskMap.insert({task->getName(), task});
        osThreadAttr_t attributes = {};
        attributes.name = task->getName().c_str();
        attributes.stack_size = 4096;
        attributes.priority = static_cast<osPriority_t>(priority);
        osThreadId_t id = osThreadNew(&taskEntrypoint, (void*)&task->getName(), &attributes);
        if (id == nullptr) {
            throw TaskCreationException("Failed to create task '" + task->getName() + "'");
        }
    }

    void Application::removeTask(Task *task) {
        taskMap.erase(task->getName());
    }
}
