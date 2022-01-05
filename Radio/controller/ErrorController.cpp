#include "ErrorController.hpp"

namespace controller {
    ErrorController::ErrorController(model::ErrorModel &errorModel)
        : errorModel(errorModel) {}

    void ErrorController::clearError() {
        errorModel.clearErrorMessage();
    }
}
