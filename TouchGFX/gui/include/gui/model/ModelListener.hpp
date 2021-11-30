#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <model/ApplicationModel.hpp>
#include <gui/containers/controls.hpp>

class ModelListener {
public:
    ModelListener()
        : applicationModel(nullptr) {}

    virtual ~ModelListener() = default;

    void bind(Model* model) {
        applicationModel = &model->getApplicationModel();
    }
    virtual void update() = 0;
protected:
    void updatePeripheralsState(controls& controls) {
        if (applicationModel == nullptr) {
            return;
        }
        const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
        controls.setEthernetState(peripheralStateModel.isEthernetState());
        controls.setSdCardState(peripheralStateModel.isSdCardState());
    }

    void getRadioStationsListModel() {

    }

    const model::ApplicationModel* applicationModel;
};

#endif // MODELLISTENER_HPP
