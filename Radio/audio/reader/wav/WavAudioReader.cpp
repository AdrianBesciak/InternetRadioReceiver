#include "WavAudioReader.hpp"
#include <array>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <string>

namespace audio {
    namespace headers {
        using Header = std::array<char, 4>;
        constexpr Header RIFF =  {'R', 'I', 'F', 'F'};
        constexpr Header WAVE = {'W', 'A', 'V', 'E'};
        constexpr Header FORMAT = {'f', 'm', 't', ' '};
        constexpr Header DATA = {'d', 'a', 't', 'a'};
    }

    struct Chunk {
        headers::Header header;
        std::uint32_t size;
    };

    WavAudioReader::WavAudioReader(const std::shared_ptr<io::ReadStream> &readStream)
        : AudioReader(readStream)
        , metadata()
        , remainingDataSize(0)
        , totalDataSize() {
        readRiffChunk();
        readFormatChunk();
        readDataChunk();
    }

    bool WavAudioReader::hasNext() const noexcept {
        return remainingDataSize != 0;
    }

    std::size_t WavAudioReader::readNext(std::int16_t *data, std::size_t count) {
        std::size_t readSize = (remainingDataSize / 2) < count ? (remainingDataSize / 2) : count;
        if (metadata.getChannelsNumber() == 1) {
            std::vector<std::uint16_t> buffer(readSize / 2);
            readStream->readExact(buffer.data(), buffer.size() * 2);
            remainingDataSize -= readSize;
            for (std::size_t i = 0; i < buffer.size(); ++i) {
                data[2 * i] = buffer[i];
                data[2 * i + 1] = buffer[i];
            }
        }
        else {
            readStream->readExact(data, readSize * 2);
            remainingDataSize -= readSize * 2;
        }
        return readSize;
    }

    void WavAudioReader::readRiffChunk() {
        Chunk riffChunk = {};
        headers::Header waveHeader = {};
        readStream->readExact(&riffChunk, sizeof(riffChunk));
        readStream->readExact(&waveHeader, sizeof(waveHeader));

        if (riffChunk.header != headers::RIFF)
            throw std::runtime_error("File '" + getName() + "' is not a riff file");
        if (waveHeader != headers::WAVE)
            throw std::runtime_error("File '" + getName() + "' is not a wave file");
    }

    void WavAudioReader::readFormatChunk() {
        Chunk formatSubChunk = {};
        readStream->readExact(&formatSubChunk, sizeof(formatSubChunk));

        if (formatSubChunk.header != headers::FORMAT)
            throw std::runtime_error("Filed to read format from '" + getName() + "'");
        const std::size_t MIN_CHUNK_SIZE = 16;
        if (formatSubChunk.size < MIN_CHUNK_SIZE || formatSubChunk.size > sizeof(WavAudioMetadata))
            throw std::runtime_error("Filed to read invalid sized format from '" + getName() + "'");


        readStream->readExact(&metadata.internal, formatSubChunk.size);
        if (metadata.getFormatTag() != WavFormatTag::PCM)
            throw std::runtime_error("Non PCM file '" + getName() + "' not supported");
        if (metadata.getChannelsNumber() > 2)
            throw std::runtime_error("Channel number greater than 2 in file '" + getName() + "' not supported");
        const std::uint16_t SUPPORTED_SAMPLING = 48000;
        if (metadata.getSamplingRate() > SUPPORTED_SAMPLING)
            throw std::runtime_error("Unsupported " + std::to_string(SUPPORTED_SAMPLING) + " sampling in file '" + getName() + "'");
    }

    void WavAudioReader::readDataChunk() {
        Chunk dataSubChunk = {};
        readStream->readExact(&dataSubChunk, sizeof(Chunk));
        if (dataSubChunk.header != headers::DATA)
            throw std::runtime_error("Failed to read data chunk from '" + getName() + "'");
        remainingDataSize = totalDataSize = dataSubChunk.size;
    }

    void WavAudioReader::seek(std::size_t pos) {
        std::ignore = pos;
        throw std::runtime_error("unimplemented yet");
        /*if (pos > getTotalDataSize())
            throw std::invalid_argument("Invalid position: " + std::to_string(pos));
        std::size_t dataStartPos = readStream->pos() - getReadDataSize();
        readStream->seek(dataStartPos + pos);
        remainingDataSize = totalDataSize - pos;*/
    }


    float WavAudioReader::getCurrentTime() const {
        return static_cast<float>(getReadDataSize())
        / static_cast<float>(metadata.getChannelsNumber())
        / static_cast<float>(metadata.getSamplingRate())
        / std::round(static_cast<float>(getMetadata().getBitsPerSample()) / 8.0F);
    }

    float WavAudioReader::getEndTime() const {
        return static_cast<float>(getTotalDataSize())
        / static_cast<float>(metadata.getChannelsNumber())
        / static_cast<float>(metadata.getSamplingRate())
        / std::round(static_cast<float>(metadata.getBitsPerSample()) / 8.0F);
    }

    const WavAudioMetadata &WavAudioReader::getMetadata() const {
        return metadata;
    }


    std::size_t WavAudioReader::getReadDataSize() const noexcept {
        return totalDataSize - remainingDataSize;
    }

    std::size_t WavAudioReader::getRemainingDataSize() const noexcept {
        return remainingDataSize;
    }

    std::size_t WavAudioReader::getTotalDataSize() const noexcept {
        return totalDataSize;
    }
}