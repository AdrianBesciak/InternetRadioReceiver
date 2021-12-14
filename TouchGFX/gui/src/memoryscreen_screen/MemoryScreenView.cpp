#include <gui/memoryscreen_screen/MemoryScreenView.hpp>

MemoryScreenView::MemoryScreenView() {}


void MemoryScreenView::setOnPlayClicked(const std::function<void()> &onPlayClicked) {
    musicControlPanel1.setOnPlayClicked(onPlayClicked);
}

void MemoryScreenView::setOnStopClicked(const std::function<void()> &onStopClicked) {
    musicControlPanel1.setOnStopClicked(onStopClicked);
}

void MemoryScreenView::setOnPauseClicked(const std::function<void()> &onPauseClicked) {
    musicControlPanel1.setOnPauseClicked(onPauseClicked);
}

void MemoryScreenView::setOnFastForwardClicked(const std::function<void()> &onFastForwardClicked) {
    musicControlPanel1.setOnFastForwardClicked(onFastForwardClicked);
}

void MemoryScreenView::setOnFastBackwardClicked(const std::function<void()> &onFastBackwardClicked) {
    musicControlPanel1.setOnFastBackwardClicked(onFastBackwardClicked);
}

void MemoryScreenView::setOnPlayNextClicked(const std::function<void()> &onPlayNextClicked) {
    musicControlPanel1.setOnPlayNextClicked(onPlayNextClicked);
}

void MemoryScreenView::setOnPlayPreviousClicked(const std::function<void()> &onPlayPreviousClicked) {
    musicControlPanel1.setOnPlayPreviousClicked(onPlayPreviousClicked);
}


void MemoryScreenView::setPeripheralState(bool ethernetState, bool sdCardState) {
    controls1.setEthernetState(ethernetState);
    controls1.setSdCardState(sdCardState);
}
