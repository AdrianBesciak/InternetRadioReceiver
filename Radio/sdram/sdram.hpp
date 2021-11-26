#pragma once

namespace sdram {
    namespace size {
        constexpr std::size_t SCREEN_BUFFER_SIZE = 480 * 272;
        constexpr std::size_t SCREEN_BUFFER_SIZE_BYTES = SCREEN_BUFFER_SIZE * 3;
        constexpr std::size_t PLAYER_BUFFER_SIZE = 8192;
        constexpr std::size_t PLAYER_BUFFER_SIZE_BYTES = PLAYER_BUFFER_SIZE * 2;
    }
    namespace addr {
        constexpr std::size_t SDRAM_START = 0xC0000000;
        constexpr std::size_t SCREEN_BUFFER1 = SDRAM_START;
        constexpr std::size_t SCREEN_BUFFER2 = SCREEN_BUFFER1 + size::SCREEN_BUFFER_SIZE_BYTES;
        constexpr std::size_t PLAYER_BUFFER = SCREEN_BUFFER2 + size::SCREEN_BUFFER_SIZE_BYTES;
    }
}
