#pragma once
#include <memory>
#include <io/stream/ReadStream.hpp>
#include <audio/reader/AudioReader.hpp>


namespace audio {
    class AudioReaderFactory {
    public:
        static std::unique_ptr<AudioReader> createReader(const std::shared_ptr<io::ReadStream> &readStream);
    };
}
