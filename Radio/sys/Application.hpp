#pragma once
#include <string>
#include <unordered_map>
#include <sys/task/TaskPriority.hpp>

namespace sys {
    class Task;
    class Application {
        friend class Task;
        friend void taskEntrypoint(void *arg);
    public:
        Application();
        static Application& getInstance();
        static void wait(std::uint32_t ticks);

    private:
        void addTask(Task *task, TaskPriority priority);
        void removeTask(Task *task);

        static Application *application;
        std::unordered_map<std::string, Task*> taskMap;
    };
}
