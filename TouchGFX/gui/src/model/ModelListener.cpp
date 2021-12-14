#include <gui/model/ModelListener.hpp>

ModelListener::ModelListener()
        : applicationModel(nullptr)
        , applicationController(nullptr) {}

ModelListener::~ModelListener() = default;

void ModelListener::bind(Model *model) {
    applicationModel = &model->getApplicationModel();
    applicationController = &model->getApplicationController();
}

void ModelListener::updatePeripheralsState(const std::function<void(bool, bool)>& peripheralStateUpdater) {
    if (applicationModel == nullptr) {
        return;
    }
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    peripheralStateUpdater(peripheralStateModel.isEthernetState(), peripheralStateModel.isSdCardState());
}
