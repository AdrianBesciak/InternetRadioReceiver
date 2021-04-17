#pragma once
#include <string>
#include <unordered_map>

namespace sys {
    namespace task {
        class Task;
    }
    class Application {
        friend class task::Task;
        friend void taskEntrypoint(void *arg);
    public:
        Application();
        static Application& getInstance();

    private:
        void addTask(task::Task *task);
        void removeTask(task::Task *task);

        static Application *application;
        std::unordered_map<std::string, sys::task::Task*> taskMap;
    };
}