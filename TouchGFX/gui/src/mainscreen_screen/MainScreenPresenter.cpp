#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <gui/mainscreen_screen/MainScreenView.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& view)
    : view(view) {}

void MainScreenPresenter::update() {
    updatePeripheralsState();
}

void MainScreenPresenter::updatePeripheralsState() {
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    PeripheralStateIndicators &peripheralStateIndicators = view.getPeripheralStateIndicators();
    peripheralStateIndicators.setEthernetState(peripheralStateModel.isEthernetState());
    peripheralStateIndicators.setSdCardState(peripheralStateModel.isSdCardState());
}
