#pragma once
#include <string>
#include <audio/WavAudioMetadata.hpp>
#include <filesystem/FileReadStream.hpp>

namespace audio {
    class WavAudioReader {
    public:
        explicit WavAudioReader(const std::string& file);
        [[nodiscard]] const std::string& getFilePath();
        [[nodiscard]] const WavAudioMetadata& getMetadata();

        [[nodiscard]] std::size_t getReadDataSize() const noexcept;
        [[nodiscard]] std::size_t getRemainingDataSize() const noexcept;
        [[nodiscard]] std::size_t getTotalDataSize() const noexcept;

        [[nodiscard]] bool hasNext() const noexcept;
        void readNext(std::vector<std::uint16_t>& data, std::size_t count);
        std::size_t readNext(std::uint16_t *data, std::size_t count);
        void seek(std::size_t pos);
    private:
        void readRiffChunk();
        void readFormatChunk();
        void readDataChunk();

        filesystem::FileReadStream readStream;
        WavAudioMetadata metadata;
        std::size_t remainingDataSize;
        std::size_t totalDataSize;
    };
}