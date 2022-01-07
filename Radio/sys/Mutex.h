#pragma once

namespace sys {
    class Mutex {
    public:
        Mutex();
        ~Mutex();
        void lock();
        void unlock();
    private:
        void* handle;
    };
}

