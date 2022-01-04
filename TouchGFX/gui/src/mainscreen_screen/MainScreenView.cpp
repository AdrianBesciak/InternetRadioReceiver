#include <gui/mainscreen_screen/MainScreenView.hpp>

MainScreenView::MainScreenView() = default;

PeripheralStateIndicators& MainScreenView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}
