#pragma once
#include <gui_generated/common/FrontendApplicationBase.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase {
public:
    FrontendApplication(Model& model, FrontendHeap& heap);
    void handleTickEvent() override;
};

