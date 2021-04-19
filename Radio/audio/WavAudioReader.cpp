#include "WavAudioReader.hpp"
#include <array>
#include <string>
#include <stm32f7xx_hal.h>
#include <iostream>
#include <cstring>

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

    WavAudioReader::WavAudioReader(const std::string &file)
        : readStream(file)
        , metadata()
        , remainingDataSize(0)
        , totalDataSize() {
        readRiffChunk();
        readFormatChunk();
        readDataChunk();
    }


    const std::string &WavAudioReader::getFilePath() {
        return readStream.getFilePath();
    }

    const WavAudioMetadata &WavAudioReader::getMetadata() {
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

    bool WavAudioReader::hasNext() const noexcept {
        return remainingDataSize != 0;
    }

    void WavAudioReader::readNext(std::vector<std::uint16_t>& data, std::size_t count) {
        std::size_t readSize = (remainingDataSize / 2) < count ? (remainingDataSize / 2) : count;
        data.resize(readSize * 2);
        readStream.read(data.data(), readSize * 2);
        remainingDataSize -= readSize;
    }

    std::size_t WavAudioReader::readNext(std::uint16_t *data, std::size_t count) {
        std::size_t readSize = (remainingDataSize / 2) < count ? (remainingDataSize / 2) : count;
        readStream.read(data, readSize * 2);
        remainingDataSize -= readSize * 2;
        std::cout << "Remaining: " << remainingDataSize << '\n';
        return readSize;
    }

    void WavAudioReader::readRiffChunk() {
        Chunk riffChunk = {};
        headers::Header waveHeader = {};
        readStream.read(&riffChunk, sizeof(riffChunk));
        readStream.read(&waveHeader, sizeof(headers::Header));

        if (riffChunk.header != headers::RIFF)
            throw std::runtime_error("File '" + getFilePath() + "' is not a riff file");
        if (waveHeader != headers::WAVE)
            throw std::runtime_error("File '" + getFilePath() + "' is not a wave file");
    }

    void WavAudioReader::readFormatChunk() {
        Chunk formatSubChunk = {};
        readStream.read(&formatSubChunk, sizeof(formatSubChunk));

        if (formatSubChunk.header != headers::FORMAT)
            throw std::runtime_error("Filed to read format from '" + getFilePath() + "'");
        const std::size_t MIN_CHUNK_SIZE = 16;
        if (formatSubChunk.size < MIN_CHUNK_SIZE || formatSubChunk.size > sizeof(WavAudioMetadata))
            throw std::runtime_error("Filed to read invalid sized format from '" + getFilePath() + "'");


        readStream.read(&metadata, formatSubChunk.size);
        if (metadata.getFormatTag() != WavFormatTag::PCM)
            throw std::runtime_error("Non PCM file '" + getFilePath() + "' not supported");
        if (metadata.getChannelsNumber() > 2)
            throw std::runtime_error("Channel number greater than 2 in file '" + getFilePath() + "' not supported");
        const std::uint16_t SUPPORTED_SAMPLING = 48000;
        if (metadata.getSamplingRate() > SUPPORTED_SAMPLING)
            throw std::runtime_error("Unsupported " + std::to_string(SUPPORTED_SAMPLING) + " sampling in file '" + getFilePath() + "'");
    }

    void WavAudioReader::readDataChunk() {
        Chunk dataSubChunk = {};
        readStream.read(&dataSubChunk, sizeof(Chunk));
        if (dataSubChunk.header != headers::DATA)
            throw std::runtime_error("Failed to read data chunk from '" + getFilePath() + "'");
        remainingDataSize = totalDataSize = dataSubChunk.size;
    }

    void WavAudioReader::seek(std::size_t pos) {
        if (pos > getTotalDataSize())
            throw std::invalid_argument("Invalid position: " + std::to_string(pos));
        std::size_t dataStartPos = readStream.pos() - getReadDataSize();
        readStream.seek(dataStartPos + pos);
        remainingDataSize = totalDataSize - pos;
    }
}