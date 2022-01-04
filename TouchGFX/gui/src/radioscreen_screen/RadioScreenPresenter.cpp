#include <gui/radioscreen_screen/RadioScreenView.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <model/RadioStationsListModel.hpp>

RadioScreenPresenter::RadioScreenPresenter(RadioScreenView& view)
    : view(view) {}


void RadioScreenPresenter::activate() {
    controller::VolumeController &volumeController = applicationController->getVolumeController();
    view.setOnVolumePlusClicked([&] { volumeController.increaseVolume();});
    view.setOnVolumeMinusClicked([&] { volumeController.decreaseVolume();});
}

void RadioScreenPresenter::deactivate() {
    view.setOnVolumePlusClicked(nullptr);
    view.setOnVolumeMinusClicked(nullptr);
}

void RadioScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
}

void RadioScreenPresenter::updatePeripheralsState() {
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    view.setEthernetState(peripheralStateModel.isEthernetState());
    view.setSdCardState(peripheralStateModel.isSdCardState());
}

void RadioScreenPresenter::updateVolume() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    view.setVolume(playerModel.getVolume());
}
