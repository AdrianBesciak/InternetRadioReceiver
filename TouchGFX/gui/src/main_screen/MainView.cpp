#include <gui/main_screen/MainView.hpp>

MainView::MainView() = default;

PeripheralStateIndicators& MainView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}
