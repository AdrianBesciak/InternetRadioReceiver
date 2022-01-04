#include <gui/model/ModelListener.hpp>

ModelListener::ModelListener()
        : applicationModel(nullptr)
        , applicationController(nullptr) {}

ModelListener::~ModelListener() = default;

void ModelListener::bind(Model *model) {
    applicationModel = &model->getApplicationModel();
    applicationController = &model->getApplicationController();
}
