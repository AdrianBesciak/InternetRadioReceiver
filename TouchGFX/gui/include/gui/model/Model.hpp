#pragma once
#include <ApplicationModule.h>
#include <model/ApplicationModel.hpp>

class ModelListener;

class Model {
public:
    Model();
    void bind(ModelListener* listener);
    void tick();

    [[nodiscard]] const model::ApplicationModel &getApplicationModel() const;
    controller::ApplicationController &getApplicationController();
    [[nodiscard]] const controller::ApplicationController &getApplicationController() const;

protected:
    ModelListener* modelListener;
};
