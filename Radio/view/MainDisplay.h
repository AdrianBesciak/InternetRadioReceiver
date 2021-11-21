#pragma once
#include <sys/task/Task.hpp>


namespace view {
    class MainDisplay : public sys::Task {
    public:
        MainDisplay();

    protected:
        void executeImpl() override;

    private:
        static MainDisplay* instance;
    };
}


