#include "Application.hpp"
#include <cmsis_os.h>
#include <sys/task/Task.hpp>

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

    void Application::addTask(sys::task::Task *task) {
        taskMap.insert({task->getName(), task});
        osThreadAttr_t attributes = {};
        attributes.name = task->getName().c_str();
        attributes.stack_size = 2048 * 4;
        attributes.priority = osPriorityNormal;
        osThreadNew(&taskEntrypoint, (void*)&task->getName(), &attributes);
    }

    void Application::removeTask(task::Task *task) {
        taskMap.erase(task->getName());
    }
}