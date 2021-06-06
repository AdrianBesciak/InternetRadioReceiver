#pragma once
#include <cstdint>

namespace audio {
    class AudioMetadata {
    public:
        virtual ~AudioMetadata();
        [[nodiscard]] virtual std::uint16_t getChannelsNumber() const noexcept = 0;
        [[nodiscard]] virtual std::uint32_t getSamplingRate() const noexcept = 0;
        [[nodiscard]] virtual std::uint16_t getBitsPerSample() const noexcept = 0;
    };
}