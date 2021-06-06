#include "WavAudioMetadata.hpp"

namespace audio {
    WavFormatTag WavAudioMetadata::getFormatTag() const noexcept {
        return internal.formatTag;
    }

    std::uint16_t WavAudioMetadata::getChannelsNumber() const noexcept {
        return internal.channelsNumber;
    }

    std::uint32_t WavAudioMetadata::getSamplingRate() const noexcept {
        return internal.samplingRate;
    }

    std::uint32_t WavAudioMetadata::getDataRate() const noexcept {
        return internal.dataRate;
    }

    std::uint16_t WavAudioMetadata::getDataBlockSize() const noexcept {
        return internal.dataBlockSize;
    }

    std::uint16_t WavAudioMetadata::getBitsPerSample() const noexcept {
        return internal.bitsPerSample;
    }
}