#pragma once
#include <audio/reader/AudioReader.hpp>
#include <audio/metadata/mpeg/MPEGAudioMetadata.hpp>
#include <spiritMP3Dec.h>

namespace audio {
    class MPEGAudioReader : public AudioReader {
    public:
        explicit MPEGAudioReader(const std::shared_ptr<io::ReadStream> &readStream);

        [[nodiscard]] bool hasNext() const noexcept override;
        std::size_t readNext(std::int16_t *data, std::size_t count) override;
        void seek(std::size_t position) override;
        [[nodiscard]] float getCurrentTime() const override;
        [[nodiscard]] float getEndTime() const override;
        [[nodiscard]] const MPEGAudioMetadata &getMetadata() const override;

    private:
        std::shared_ptr<TSpiritMP3Decoder> decoder;
        MPEGAudioMetadata audioMetadata;
    };
}
