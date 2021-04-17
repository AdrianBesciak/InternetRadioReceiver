#pragma once
#include <cstdint>

namespace audio {
    enum class WavFormatTag : std::uint16_t {
        PCM = 0x0001,
        IEEE_FLOAT = 0x0003,
        ALAW = 0x0006,
        MULAW = 0x0007,
        EXTENSIBLE = 0xFFFE
    };
}