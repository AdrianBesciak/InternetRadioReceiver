#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& view)
    : view(view) {}

void MainPresenter::update() {
    updatePeripheralsState([&](auto... states) {view.setPeripheralState(states...);});
}
