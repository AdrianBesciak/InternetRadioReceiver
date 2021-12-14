#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& model, FrontendHeap& heap)
    : FrontendApplicationBase(model, heap) {}

void FrontendApplication::handleTickEvent() {
    model.tick();
    FrontendApplicationBase::handleTickEvent();
}
