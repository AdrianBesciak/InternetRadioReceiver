#include "cmsis_os.h"

osSemaphoreId osSemaphoreCreate (const osSemaphoreDef_t *semaphore_def, int32_t count) {
    return osSemaphoreNew(count, count, semaphore_def);
}

int32_t osSemaphoreWait (osSemaphoreId semaphore_id, uint32_t millisec) {
    return osSemaphoreAcquire(semaphore_id, millisec);
}