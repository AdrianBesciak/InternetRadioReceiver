#include <gui/radioscreen_screen/RadioScreenView.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <model/RadioStationsListModel.hpp>

RadioScreenPresenter::RadioScreenPresenter(RadioScreenView& view)
    : view(view) {}


void RadioScreenPresenter::activate() {
    view.setOnPlayClicked([&] {applicationController->playRadio();});
    view.setOnStopClicked([&] {applicationController->stop();});
}

void RadioScreenPresenter::deactivate() {
    view.setOnPlayClicked(nullptr);
    view.setOnStopClicked(nullptr);
}

void RadioScreenPresenter::update() {
    updatePeripheralsState([&](auto... states) {view.setPeripheralState(states...);});
    updateCurrentRadioStationName();
    updateRadioStationsList();
}

void RadioScreenPresenter::updateCurrentRadioStationName() {
    const auto& stations = applicationModel->getRadioStationsListModel().getRadioStations();
    auto current_index = applicationModel->getRadioStationsListModel().getCurrentStationIndex();
    view.setTitle(stations.at(current_index).getName());
}

void RadioScreenPresenter::updateRadioStationsList() {
    const auto& stations = applicationModel->getRadioStationsListModel().getRadioStations();
    auto current_index = applicationModel->getRadioStationsListModel().getCurrentStationIndex();
    view.fillRadioStationsList(stations, current_index);
}
