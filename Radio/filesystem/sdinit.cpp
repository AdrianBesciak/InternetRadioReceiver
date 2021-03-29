#include "sdinit.hpp"
#include <stdexcept>
#include <fatfs.h>

namespace filesystem {
    void initializeSD() {
        static bool initialized = false;
        if (!initialized) {
            if (f_mount(&SDFatFS, SDPath, 1) != FR_OK) {
                throw std::runtime_error("Failed to initialize SD card");
            }
            initialized = true;
        }
    }
}