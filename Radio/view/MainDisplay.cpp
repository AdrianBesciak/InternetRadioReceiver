#include "MainDisplay.h"
#include <stm32f7xx_hal.h>
extern "C" {
#include <app_touchgfx.h>
}
#include <sys/except/SingleInstanceException.hpp>

namespace view {
    MainDisplay::MainDisplay()
        : sys::Task("IRR_MainDisplay") {
        if (instance != nullptr)
            throw sys::SingleInstanceException("ScreenDisplay instance already exists");
        instance = this;
        HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOI, GPIO_PIN_12, GPIO_PIN_SET);
    }

    void MainDisplay::executeImpl() {
        MX_TouchGFX_Process();
    }

    MainDisplay* MainDisplay::instance = nullptr;
}
