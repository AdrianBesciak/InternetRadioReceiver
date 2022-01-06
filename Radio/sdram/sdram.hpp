#pragma once

namespace sdram {
    namespace size {
        constexpr std::size_t SCREEN_BUFFER_SIZE = 480 * 272;
        constexpr std::size_t SCREEN_BUFFER_SIZE_BYTES = SCREEN_BUFFER_SIZE * 3;
    }
    namespace addr {
        constexpr std::size_t SDRAM_START = 0xC0000000;
        constexpr std::size_t SCREEN_BUFFER1 = SDRAM_START;
        constexpr std::size_t SCREEN_BUFFER2 = SCREEN_BUFFER1 + size::SCREEN_BUFFER_SIZE_BYTES;
    }
}
