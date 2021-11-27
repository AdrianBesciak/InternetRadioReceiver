#pragma once
#include <audio/reader/AudioReader.hpp>
#include <audio/metadata/vorbis/VorbisAudioMetadata.hpp>

namespace audio {
    class VorbisAudioReader : public AudioReader {
    public:
        explicit VorbisAudioReader(const std::shared_ptr<io::ReadStream> &readStream);
        ~VorbisAudioReader();

        size_t readNext(std::int16_t *data, std::size_t count) override;
        void seek(std::size_t position) override;
        void seek(float time) override;

        [[nodiscard]] float getCurrentTime() const override;
        [[nodiscard]] float getEndTime() const override;
        [[nodiscard]] const VorbisAudioMetadata &getMetadata() const override;

    private:
        class VorbisInputBuffer;
        class VorbisOutputBuffer;
        std::shared_ptr<VorbisInputBuffer> inputBuffer;
        std::shared_ptr<VorbisOutputBuffer> outputBuffer;
        VorbisAudioMetadata audioMetadata;
    };
}
