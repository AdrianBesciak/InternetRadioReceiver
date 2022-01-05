#pragma once
#include <string>

namespace model {
    class ErrorModel {
    public:
        ErrorModel();

        [[nodiscard]] const std::string &getErrorMessage() const;
        void setErrorMessage(const std::string &errorMessage);
        void clearErrorMessage();

    private:
        std::string errorMessage;
    };
}

