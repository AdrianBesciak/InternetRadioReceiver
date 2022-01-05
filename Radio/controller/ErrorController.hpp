#pragma once
#include <model/ErrorModel.hpp>

namespace controller {
    class ErrorController {
    public:
        explicit ErrorController(model::ErrorModel &errorModel);
        void clearError();

    private:
        model::ErrorModel& errorModel;
    };
}


