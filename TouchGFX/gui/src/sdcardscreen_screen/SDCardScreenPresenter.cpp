#include <gui/sdcardscreen_screen/SDCardScreenPresenter.hpp>
#include <gui/sdcardscreen_screen/SDCardScreenView.hpp>

SDCardScreenPresenter::SDCardScreenPresenter(SDCardScreenView& view)
    : view(view) {}

void SDCardScreenPresenter::activate() {
    controller::VolumeController &volumeController = applicationController->getVolumeController();
    view.setOnVolumePlusClicked([&] { volumeController.increaseVolume();});
    view.setOnVolumeMinusClicked([&] { volumeController.decreaseVolume();});
}

void SDCardScreenPresenter::deactivate() {
    view.setOnVolumePlusClicked(nullptr);
    view.setOnVolumeMinusClicked(nullptr);
}

void SDCardScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
}

void SDCardScreenPresenter::updatePeripheralsState() {
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    view.setEthernetState(peripheralStateModel.isEthernetState());
    view.setSdCardState(peripheralStateModel.isSdCardState());
}

void SDCardScreenPresenter::updateVolume() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    view.setVolume(playerModel.getVolume());
}
