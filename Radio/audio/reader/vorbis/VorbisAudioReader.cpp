#include "VorbisAudioReader.hpp"
#include <cstring>
#include <iostream>
#include <functional>
#include <stb_vorbis.h>
#include <audio/except/reader/AudioReaderDecodeException.hpp>
#include <audio/except/reader/InvalidAudioFormatException.hpp>
#include <except/UnimplementedException.hpp>

namespace audio {
    class VorbisAudioReader::VorbisInputBuffer {
    public:
        explicit VorbisInputBuffer(const std::shared_ptr<io::ReadStream> &readStream, std::size_t size)
                : readStream(readStream)
                , buffer(size)
                , startOffset(0)
                , endOffset(0) {}

        [[nodiscard]] std::uint8_t* getBuffer() {
            return buffer.data() + startOffset;
        }

        [[nodiscard]] std::size_t getLength() const {
            return endOffset - startOffset;
        }

        [[nodiscard]] bool isEmpty() const {
            return getLength() == 0 && readStream->pos() == readStream->size();
        }

        void shiftBy(std::size_t shift) {
            startOffset += shift;
        }

        void readData() {
            std::size_t length = getLength();
            std::memmove(buffer.data() , buffer.data() + startOffset, length);
            startOffset = 0;
            endOffset = length;
            std::size_t readCount = readStream->read(buffer.data() + endOffset, buffer.size() - length);
            endOffset += readCount;
        }

    private:
        std::shared_ptr<io::ReadStream> readStream;
        std::vector<std::uint8_t> buffer;
        std::size_t startOffset;
        std::size_t endOffset;
    };


    class VorbisAudioReader::VorbisOutputBuffer {
    public:
        explicit VorbisOutputBuffer(VorbisInputBuffer& inputBuffer, std::size_t bufferSize)
                : inputBuffer(inputBuffer)
                , buffer(bufferSize)
                , decoder(nullptr)
                , samples(nullptr)
                , sampleStartOffset(0)
                , sampleEndOffset(0) {
            openDecoder();
        }

        ~VorbisOutputBuffer() {
            stb_vorbis_close(decoder);
        }

        [[nodiscard]] stb_vorbis_info getStreamInfo() const {
            return stb_vorbis_get_info(decoder);
        }

        std::size_t read(std::int16_t* data, std::size_t count) {
            std::size_t remainingCount = count / 2;
            bool dataAcquired = true;
            do {
                std::size_t sampleCount = std::min(remainingCount, sampleEndOffset - sampleStartOffset);
                for (std::size_t i = 0; i < sampleCount; ++i) {
                    *(data) = realSampleToIntegralSample(samples[0][i + sampleStartOffset]);
                    *(data + 1) = realSampleToIntegralSample(samples[1][i + sampleStartOffset]);
                    data += 2;
                }
                remainingCount -= sampleCount;
                sampleStartOffset += sampleCount;
                if (remainingCount != 0) {
                    dataAcquired = decodeData();
                }
            } while (remainingCount != 0 && dataAcquired);
            return count - 2 * remainingCount;
        }

    private:
        void openDecoder() {
            stb_vorbis_alloc alloc{buffer.data(), static_cast<int>(buffer.size())};
            int dataUsed = 0;
            int error = 0;

            inputBuffer.readData();
            decoder = stb_vorbis_open_pushdata(inputBuffer.getBuffer(), static_cast<int>(inputBuffer.getLength()), &dataUsed, &error, &alloc);
            inputBuffer.shiftBy(static_cast<std::size_t>(dataUsed));

            if (error == VORBIS_need_more_data || error == VORBIS_outofmem) {
                throw AudioReaderDecodeException("Failed to read stream - not enough resources to process");
            }
            else if (error != 0) {
                throw InvalidAudioFormatException("Failed to read stream - not a vorbis stream");
            }
            stb_vorbis_info  info = getStreamInfo();
            // TODO make this work for single channel
            if (info.channels != 2) {
                throw AudioReaderDecodeException("Only two channels are supported");
            }
        }

        bool decodeData() {
            if (inputBuffer.isEmpty()) {
                return false;
            }
            inputBuffer.readData();
            float **newSamples = nullptr;
            int newSamplesCount = 0;
            int dataUsed = stb_vorbis_decode_frame_pushdata(decoder, inputBuffer.getBuffer(), static_cast<int>(inputBuffer.getLength()), nullptr, &newSamples, &newSamplesCount);
            if (dataUsed == 0) {
                int error = stb_vorbis_get_error(decoder);
                if (error == VORBIS_need_more_data) {
                    inputBuffer.readData();
                    dataUsed = stb_vorbis_decode_frame_pushdata(decoder, inputBuffer.getBuffer(), static_cast<int>(inputBuffer.getLength()), nullptr, &newSamples, &newSamplesCount);
                    error = stb_vorbis_get_error(decoder);
                }
                if (error != 0) {
                    throw AudioReaderDecodeException("Failed to decode samples");
                }
            }
            inputBuffer.shiftBy(static_cast<std::size_t>(dataUsed));
            samples = newSamples;
            sampleStartOffset = 0;
            sampleEndOffset = static_cast<std::size_t>(newSamplesCount);
            return true;
        }

        static constexpr std::int16_t realSampleToIntegralSample(float realSample) {
            realSample *= 32768;
            if (realSample > 32767) {
                realSample = 32767;
            }
            if (realSample < -32768){
                realSample = -32768;
            }
            return (std::int16_t)realSample;
        }

        VorbisInputBuffer &inputBuffer;
        std::vector<char> buffer;
        stb_vorbis* decoder;
        float** samples;
        std::size_t sampleStartOffset;
        std::size_t sampleEndOffset;
    };


    VorbisAudioReader::VorbisAudioReader(const std::shared_ptr<io::ReadStream> &readStream)
        : AudioReader(readStream)
        , inputBuffer(std::make_shared<VorbisInputBuffer>(readStream, 8192))
        , outputBuffer(std::make_shared<VorbisOutputBuffer>(*inputBuffer, 210000))
        , audioMetadata(){
        stb_vorbis_info info = outputBuffer->getStreamInfo();
        audioMetadata = VorbisAudioMetadata(&info);
    }

    VorbisAudioReader::~VorbisAudioReader() = default;

    std::size_t VorbisAudioReader::readNext(std::int16_t *data, std::size_t count) {
        return outputBuffer->read(data, count);
    }

    void VorbisAudioReader::seek(std::size_t position) {
        std::ignore = position;
        throw except::UnimplementedException();
    }

    float VorbisAudioReader::getCurrentTime() const {
        throw except::UnimplementedException();
    }

    float VorbisAudioReader::getEndTime() const {
        throw except::UnimplementedException();
    }

    const VorbisAudioMetadata &VorbisAudioReader::getMetadata() const {
        return audioMetadata;
    }
}
