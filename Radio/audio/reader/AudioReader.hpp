#pragma once
#include <audio/metadata/AudioMetadata.hpp>
#include <io/stream/ReadStream.hpp>
#include <memory>
#include <cstdint>

namespace audio {
    class AudioReader {
    public:
        explicit AudioReader(const std::shared_ptr<io::ReadStream> &readStream);
        virtual ~AudioReader();

        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] virtual bool hasNext() const noexcept;

        [[nodiscard]] bool isRandomAccess() const;

        [[nodiscard]] virtual std::size_t readNext(std::int16_t *data, std::size_t count) = 0;
        virtual void seek(std::size_t position) = 0;
        virtual void seek(float time) = 0;

        [[nodiscard]] virtual float getCurrentTime() const = 0;
        [[nodiscard]] virtual float getEndTime() const = 0;
        [[nodiscard]] virtual const AudioMetadata& getMetadata() const = 0;

    protected:
        std::shared_ptr<io::ReadStream> readStream;
    };
}
