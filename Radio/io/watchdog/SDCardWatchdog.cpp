#include "SDCardWatchdog.hpp"
#include <fatfs.h>
#include <cstring>

extern Disk_drvTypeDef  disk;

namespace io {
    SDCardWatchdog::SDCardWatchdog()
        : Watchdog("IRR_SDCardWatchdog") {}

    void SDCardWatchdog::executeIteration() {
        bool newState = false;
        if (BSP_SD_IsDetected()) {
            if (getState()) {
                newState = true;
            }
            else {
                FRESULT result = f_mount(&SDFatFS, SDPath, 1);
                if (result != FR_OK) {
                    std::printf("Failed to mount SDCard - %d\n", result);
                }
                else {
                    newState = true;
                }
            }
        }
        else if (getState()) {
            f_mount(nullptr, "", 0);
            disk.is_initialized[0] = 0;
            std::memset(&SDFatFS, 0, sizeof(SDFatFS));
        }
        changeState(newState);
    }
}
