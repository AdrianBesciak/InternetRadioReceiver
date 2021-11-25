#include "sdinit.hpp"
#include <iostream>
#include <stdexcept>
#include <fatfs.h>

namespace init {
    void initializeSD() {
        static bool initialized = false;

        if (!initialized) {
            std::cout << "[INIT] Initializing SD Card\n";
            if (f_mount(&SDFatFS, SDPath, 1) != FR_OK) {
                throw std::runtime_error("Failed to initialize SD card");
            }

            std::cout << "[INIT] SD Card initialized\n";
            initialized = true;
        }
    }
}
