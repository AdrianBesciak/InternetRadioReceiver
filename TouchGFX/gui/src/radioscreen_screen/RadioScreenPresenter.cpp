#include <gui/radioscreen_screen/RadioScreenView.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <model/RadioStationsListModel.hpp>

RadioScreenPresenter::RadioScreenPresenter(RadioScreenView& view)
    : view(view) {}

void RadioScreenPresenter::update() {
    updatePeripheralsState(view.getControls());
    updateRadioStationsList();
}

void RadioScreenPresenter::updateRadioStationsList() {
    const auto& stations = applicationModel->getRadioStationsListModel().getRadioStations();
    auto current_index = applicationModel->getRadioStationsListModel().getCurrentStationIndex();
    view.fillRadioStationsList(stations, current_index);
}
