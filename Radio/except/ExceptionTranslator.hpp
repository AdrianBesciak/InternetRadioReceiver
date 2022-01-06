#pragma once
#include <stdexcept>
#include <string>
#include <functional>

namespace except {
    class ExceptionTranslator {
    public:
        ExceptionTranslator();
        void translate(const std::exception &exception);

        [[nodiscard]] const std::function<void(const std::string &)> &getOnErrorMessage() const;
        void setOnErrorMessage(const std::function<void(const std::string &)> &onErrorMessage);

    private:
        std::function<void(const std::string&)> onErrorMessage;
    };
}
