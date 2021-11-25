#pragma once
#include <string>
#include <cmsis_os.h>
#include <sys/task/TaskPriority.hpp>
#include <sys/Application.hpp>


namespace sys {
    class Task {
        friend class Application;
        friend void taskEntrypoint(void *arg);
    public:
        explicit Task(const std::string &name);
        virtual ~Task();
        [[nodiscard]] const std::string& getName() const;
        void startTask(TaskPriority priority = TaskPriority::NORMAL);

    protected:
        void execute();
        virtual void executeImpl() = 0;
    private:
        std::string name;
    };
}
