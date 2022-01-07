#include "Mutex.h"
#include <sys/except/MutexException.hpp>
#include <cmsis_os2.h>

namespace sys {
    Mutex::Mutex()
        : handle(nullptr) {
        handle = osMutexNew(nullptr);
        if (handle == nullptr) {
            throw MutexException("Failed to create mutex");
        }
    }

    Mutex::~Mutex() {
        if (handle != nullptr) {
            osMutexDelete(handle);
        }
    }

    void Mutex::lock() {
        if (osMutexAcquire(handle, 3000) != osOK) {
            throw MutexException("Failed to lock mutex");
        }
    }

    void Mutex::unlock() {
        if (osMutexRelease(handle) != osOK) {
            throw MutexException("Failed to unlock mutex");
        }
    }
}
