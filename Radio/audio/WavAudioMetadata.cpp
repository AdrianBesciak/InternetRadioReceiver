#include "WavAudioMetadata.hpp"

namespace audio {
    WavFormatTag WavAudioMetadata::getFormatTag() const noexcept {
        return formatTag;
    }

    std::uint16_t WavAudioMetadata::getChannelsNumber() const noexcept {
        return channelsNumber;
    }

    std::uint32_t WavAudioMetadata::getSamplingRate() const noexcept {
        return samplingRate;
    }

    std::uint32_t WavAudioMetadata::getDataRate() const noexcept {
        return dataRate;
    }

    std::uint16_t WavAudioMetadata::getDataBlockSize() const noexcept {
        return dataBlockSize;
    }

    std::uint16_t WavAudioMetadata::getBitsPerSample() const noexcept {
        return bitsPerSample;
    }
}