#include "ErrorModel.hpp"

namespace model {
    ErrorModel::ErrorModel()
        : errorMessage() {}

    const std::string &ErrorModel::getErrorMessage() const {
        return errorMessage;
    }

    void ErrorModel::setErrorMessage(const std::string &errorMessage) {
        this->errorMessage = errorMessage;
    }

    void ErrorModel::clearErrorMessage() {
        errorMessage.clear();
    }
}
