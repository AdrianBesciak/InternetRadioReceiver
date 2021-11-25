#pragma once

namespace sys {
    enum class TaskPriority {
        LOW = 8,
        BELOW_NORMAL = 16,
        NORMAL = 24,
        ABOVE_NORMAL = 32,
        HIGH = 40,
        REALTIME = 48
    };
}
