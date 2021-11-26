#include "AudioReaderFactory.hpp"
#include <stdexcept>
#include <audio/reader/mpeg/MPEGAudioReader.hpp>
#include <audio/reader/vorbis/VorbisAudioReader.hpp>
#include <audio/reader/wav/WavAudioReader.hpp>

namespace audio {
    std::unique_ptr<AudioReader> AudioReaderFactory::createReader(const std::shared_ptr<io::ReadStream> &readStream) {
        std::string mimeType = readStream->getMimeType();
        if (mimeType == "audio/mpeg") {
            return std::make_unique<MPEGAudioReader>(readStream);
        }
        if (mimeType == "application/ogg" || mimeType == "audio/ogg" || mimeType == "audio/vorbis" || mimeType == "audio/vorbis-config") {
            return std::make_unique<VorbisAudioReader>(readStream);
        }
        if (mimeType == "audio/wav") {
            return std::make_unique<WavAudioReader>(readStream);
        }
        throw std::runtime_error("Unknown mime type - " + mimeType);
    }
}
