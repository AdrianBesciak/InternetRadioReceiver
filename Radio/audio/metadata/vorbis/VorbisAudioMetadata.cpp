#include "VorbisAudioMetadata.hpp"
#include <stb_vorbis.h>

namespace audio {
    VorbisAudioMetadata::VorbisAudioMetadata()
        : channelsNumber()
        , samplingRate() {}

    VorbisAudioMetadata::VorbisAudioMetadata(void *streamInfoPtr)
        : VorbisAudioMetadata() {
        auto* info = (stb_vorbis_info*)streamInfoPtr;
        samplingRate = info->sample_rate;
    }

    uint16_t VorbisAudioMetadata::getChannelsNumber() const noexcept {
        return channelsNumber;
    }

    uint32_t VorbisAudioMetadata::getSamplingRate() const noexcept {
        return samplingRate;
    }

    uint16_t VorbisAudioMetadata::getBitsPerSample() const noexcept {
        return 16;
    }
}
