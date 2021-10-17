#pragma once
#include <audio/metadata/AudioMetadata.hpp>

namespace audio {
    class VorbisAudioMetadata : public AudioMetadata {
    public:
        VorbisAudioMetadata();
        explicit VorbisAudioMetadata(void *streamInfoPtr);
        [[nodiscard]] std::uint16_t getChannelsNumber() const noexcept override;
        [[nodiscard]] std::uint32_t getSamplingRate() const noexcept override;
        [[nodiscard]] std::uint16_t getBitsPerSample() const noexcept override;

    private:
        std::uint16_t channelsNumber;
        std::uint32_t samplingRate;
    };
}
