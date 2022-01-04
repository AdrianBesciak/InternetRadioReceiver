#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <gui/mainscreen_screen/MainScreenView.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& view)
    : view(view) {}

void MainScreenPresenter::update() {
    updatePeripheralsState([&](auto... states) {view.setPeripheralState(states...);});
}
