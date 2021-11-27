#include <gui/memoryscreen_screen/MemoryScreenView.hpp>
#include <gui/memoryscreen_screen/MemoryScreenPresenter.hpp>

MemoryScreenPresenter::MemoryScreenPresenter(MemoryScreenView& view)
    : view(view) {}

void MemoryScreenPresenter::update() {
    updatePeripheralsState(view.getControls());
}
