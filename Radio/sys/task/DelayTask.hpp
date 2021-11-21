#include <sys/task/Task.hpp>

namespace sys {
    class DelayTask : public Task {
    public:
        DelayTask(const std::string &name, std::uint32_t delay);

        [[nodiscard]] std::uint32_t getDelay() const;

    protected:
        void executeImpl() override;
        virtual void executeIteration() = 0;

    private:
        std::uint32_t delay;
    };

}
