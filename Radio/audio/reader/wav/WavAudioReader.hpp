#pragma once
#include <audio/reader/AudioReader.hpp>
#include <audio/metadata/wav/WavAudioMetadata.hpp>

namespace audio {
    class WavAudioReader : public AudioReader {
    public:
        explicit WavAudioReader(const std::shared_ptr<io::ReadStream> &readStream);

        [[nodiscard]] bool hasNext() const noexcept override;
        std::size_t readNext(std::int16_t *data, std::size_t count) override;
        void seek(std::size_t pos) override;

        [[nodiscard]] float getCurrentTime() const override;
        [[nodiscard]] float getEndTime() const override;

        [[nodiscard]] const WavAudioMetadata& getMetadata() const override;

        [[nodiscard]] std::size_t getReadDataSize() const noexcept;
        [[nodiscard]] std::size_t getRemainingDataSize() const noexcept;
        [[nodiscard]] std::size_t getTotalDataSize() const noexcept;

    private:
        void readRiffChunk();
        void readFormatChunk();
        void readDataChunk();

        WavAudioMetadata metadata;
        std::size_t remainingDataSize;
        std::size_t totalDataSize;
    };
}