#include "AudioReader.hpp"

namespace audio {
    AudioReader::AudioReader(const std::shared_ptr<io::ReadStream> &readStream)
        : readStream(readStream) {}

    const std::string &AudioReader::getName() const {
        return readStream->getName();
    }
}