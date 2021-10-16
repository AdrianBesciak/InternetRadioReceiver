#include "MPEGAudioMetadata.hpp"
#include <spiritMP3Dec.h>

namespace audio {
    MPEGAudioMetadata::MPEGAudioMetadata()
        : layer()
        , samplingRate()
        , bitrateKbps() {}

    MPEGAudioMetadata::MPEGAudioMetadata(void *frameInfoPtr)
        : MPEGAudioMetadata(){
        auto* frameInfo = (TSpiritMP3Info*)frameInfoPtr;
        layer = frameInfo->nLayer;
        samplingRate = frameInfo->nSampleRateHz;
        bitrateKbps = frameInfo->nBitrateKbps;
    }

    std::uint32_t MPEGAudioMetadata::getLayer() const {
        return layer;
    }

    std::uint16_t MPEGAudioMetadata::getChannelsNumber() const noexcept {
        return 2;
    }

    std::uint32_t MPEGAudioMetadata::getSamplingRate() const noexcept {
        return samplingRate;
    }

    std::uint16_t MPEGAudioMetadata::getBitsPerSample() const noexcept {
        return 16;
    }

    std::uint32_t MPEGAudioMetadata::getBitrateKbps() const {
        return bitrateKbps;
    }
}