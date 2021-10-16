#pragma once
#include <audio/metadata/AudioMetadata.hpp>

namespace audio {
    class MPEGAudioMetadata : public AudioMetadata {
    public:
        explicit MPEGAudioMetadata();
        explicit MPEGAudioMetadata(void *frameInfoPtr);
        [[nodiscard]] std::uint32_t getLayer() const;
        [[nodiscard]] std::uint16_t getChannelsNumber() const noexcept override;
        [[nodiscard]] std::uint32_t getSamplingRate() const noexcept override;
        [[nodiscard]] std::uint32_t getBitrateKbps() const;
        [[nodiscard]] std::uint16_t getBitsPerSample() const noexcept override;
    private:
        std::uint32_t layer;
        std::uint32_t samplingRate;
        std::uint32_t bitrateKbps;
    };
}