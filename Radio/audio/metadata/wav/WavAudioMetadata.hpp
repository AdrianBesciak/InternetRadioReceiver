#pragma once
#include <audio/metadata/AudioMetadata.hpp>
#include <audio/metadata/wav/WavFormatTag.hpp>

namespace audio {
    class WavAudioMetadata : public AudioMetadata {
    public:
        [[nodiscard]] std::uint16_t getChannelsNumber() const noexcept override;

        [[nodiscard]] std::uint32_t getSamplingRate() const noexcept override;

        [[nodiscard]] std::uint16_t getBitsPerSample() const noexcept override;

        [[nodiscard]] WavFormatTag getFormatTag() const noexcept;

        [[nodiscard]] std::uint32_t getDataRate() const noexcept;

        [[nodiscard]] std::uint16_t getDataBlockSize() const noexcept;

        struct Internal {
            WavFormatTag formatTag;
            std::uint16_t channelsNumber;
            std::uint32_t samplingRate;
            std::uint32_t dataRate;
            std::uint16_t dataBlockSize;
            std::uint16_t bitsPerSample;
            char dummy[24];
        } __attribute__((packed));
        Internal internal;
    };
}