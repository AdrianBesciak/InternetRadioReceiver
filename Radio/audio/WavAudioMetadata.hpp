#pragma once
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>
#include <audio/WavFormatTag.hpp>

namespace audio {
    class WavAudioMetadata {
    public:
        [[nodiscard]] WavFormatTag getFormatTag() const noexcept;
        [[nodiscard]] std::uint16_t getChannelsNumber() const noexcept;
        [[nodiscard]] std::uint32_t getSamplingRate() const noexcept;
        [[nodiscard]] std::uint32_t getDataRate() const noexcept;
        [[nodiscard]] std::uint16_t getDataBlockSize() const noexcept;
        [[nodiscard]] std::uint16_t getBitsPerSample() const noexcept;

    private:
        WavFormatTag formatTag;
        std::uint16_t channelsNumber;
        std::uint32_t samplingRate;
        std::uint32_t dataRate;
        std::uint16_t dataBlockSize;
        std::uint16_t bitsPerSample;
        char dummy[24];
    } __attribute__((packed));
}