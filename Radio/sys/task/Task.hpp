#pragma once
#include <string>
#include <cmsis_os.h>
#include <sys/Application.hpp>


namespace sys::task {
    class Task {
    public:
        explicit Task(const std::string &name);
        virtual ~Task();

        [[nodiscard]] const std::string& getName() const;
        void execute();

    protected:
        virtual void executeImpl() = 0;
    private:
        std::string name;
    };
}
