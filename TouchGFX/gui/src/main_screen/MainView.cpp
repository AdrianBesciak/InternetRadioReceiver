#include <gui/main_screen/MainView.hpp>

MainView::MainView() = default;

void MainView::setPeripheralState(bool ethernetState, bool sdCardState) {
    controls1.setEthernetState(ethernetState);
    controls1.setSdCardState(sdCardState);
}
