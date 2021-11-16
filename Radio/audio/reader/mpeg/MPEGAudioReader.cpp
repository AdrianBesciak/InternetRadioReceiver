#include "MPEGAudioReader.hpp"
#include <stdexcept>

namespace audio {
    unsigned int mp3ReadCallback(void * pMP3CompressedData, unsigned int nMP3DataSizeInChars, void * token) {
        auto *stream = (io::ReadStream*)(token);
        return stream->read(pMP3CompressedData, nMP3DataSizeInChars);
    }

    MPEGAudioReader::MPEGAudioReader(const std::shared_ptr<io::ReadStream> &readStream)
    : AudioReader(readStream)
    , decoder(std::make_shared<TSpiritMP3Decoder>()){
        SpiritMP3DecoderInit(decoder.get(), &mp3ReadCallback, nullptr, readStream.get());
        std::vector<std::int16_t> dummyData(1);
        TSpiritMP3Info frameInfo = {};
        SpiritMP3Decode(decoder.get(), dummyData.data(), 0, &frameInfo);
        if (frameInfo.nSampleRateHz == 0) {
            throw std::runtime_error("Stream is not an mpeg audio");
        }
        audioMetadata = MPEGAudioMetadata(&frameInfo);
    }

    std::size_t MPEGAudioReader::readNext(std::int16_t *data, std::size_t count) {
        return SpiritMP3Decode(decoder.get(), data, count / 2, nullptr);
    }

    void MPEGAudioReader::seek(std::size_t position) {
        throw std::runtime_error("unimplemented yet");
    }

    float MPEGAudioReader::getCurrentTime() const {
        std::uint32_t bytesPerSecond = audioMetadata.getBitrateKbps() * 250;
        return static_cast<float>(readStream->pos()) / static_cast<float>(bytesPerSecond);
    }

    float MPEGAudioReader::getEndTime() const {
        if (readStream->size() == static_cast<std::size_t>(-1)) {
            return getCurrentTime() + 0.01f;
        }
        std::uint32_t bytesPerSecond = audioMetadata.getBitrateKbps() * 250;
        return static_cast<float>(readStream->size()) / static_cast<float>(bytesPerSecond);
    }

    const MPEGAudioMetadata &MPEGAudioReader::getMetadata() const {
        return audioMetadata;
    }
}