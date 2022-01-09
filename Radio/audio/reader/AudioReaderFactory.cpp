#include "AudioReaderFactory.hpp"
#include <stdexcept>
#include <audio/reader/mpeg/MPEGAudioReader.hpp>
#include <audio/reader/wav/WavAudioReader.hpp>

namespace audio {
    std::unique_ptr<AudioReader> AudioReaderFactory::createReader(const std::shared_ptr<io::ReadStream> &readStream) {
        std::string mimeType = readStream->getMimeType();
        if (mimeType == "audio/mpeg") {
            return std::make_unique<MPEGAudioReader>(readStream);
        }
        if (mimeType == "audio/wav") {
            return std::make_unique<WavAudioReader>(readStream);
        }
        throw std::invalid_argument("Unknown mime type - " + mimeType);
    }
}
