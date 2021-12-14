#pragma once
#include <gui/model/Model.hpp>
#include <model/ApplicationModel.hpp>

class ModelListener {
public:
    ModelListener();
    virtual ~ModelListener();

    void bind(Model* model);
    virtual void update() = 0;
protected:
    void updatePeripheralsState(const std::function<void(bool, bool)>& peripheralStateUpdater);

    const model::ApplicationModel* applicationModel;
    controller::ApplicationController* applicationController;
};
