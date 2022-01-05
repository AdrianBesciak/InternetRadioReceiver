#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <ApplicationModule.h>

Model::Model()
    : modelListener(nullptr) {}

void Model::bind(ModelListener *modelListener) {
    this->modelListener = modelListener;
}

void Model::tick() {
    if (modelListener != nullptr) {
        modelListener->update();
    }
}
const model::ApplicationModel &Model::getApplicationModel() const {
    return ApplicationModule::getInstance().getApplicationModel();
}

controller::ApplicationController &Model::getApplicationController() {
    return ApplicationModule::getInstance().getApplicationController();
}
