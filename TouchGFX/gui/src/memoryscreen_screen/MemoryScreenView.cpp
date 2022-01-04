#include <gui/memoryscreen_screen/MemoryScreenView.hpp>

MemoryScreenView::MemoryScreenView() = default;

PeripheralStateIndicators& MemoryScreenView::getPeripheralStateIndicators() {
    return peripheralStateIndicators;
}

VolumePanel& MemoryScreenView::getVolumePanel() {
    return volumePanel;
}

TitleView& MemoryScreenView::getTitleView() {
    return titleView;
}

TimePanelInterface& MemoryScreenView::getTimePanel() {
    return timePanel;
}

ControlPanelSD& MemoryScreenView::getControlPanel() {
    return controlPanel;
}
