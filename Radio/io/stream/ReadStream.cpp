#include "ReadStream.hpp"
#include <io/except/read/StreamReadException.hpp>

namespace io {
    ReadStream::~ReadStream() = default;

    void ReadStream::readExact(void *buffer, std::size_t count) {
        std::size_t readCount = read(buffer, count);
        if (readCount != count)
            throwReadException("Read " + std::to_string(readCount) + " bytes instead of " + std::to_string(count));
    }

    std::vector<std::byte> ReadStream::read(std::size_t count) {
        std::vector<std::byte> result(count);
        std::size_t readCount = read(result.data(), count);
        result.resize(readCount);
        return result;
    }

    std::vector<std::byte> ReadStream::readExact(std::size_t count) {
        std::vector<std::byte> result(count);
        readExact(result.data(), count);
        return result;
    }

    std::string ReadStream::readLine() {
        char current;
        std::string result;
        while (true) {
            std::size_t count = read(&current, 1);
            if (count == 0 || current == '\n') {
                break;
            }
            result.push_back(current);
        }
        return result;
    }

    bool ReadStream::hasNext() const {
        return pos() != size();
    }

    bool ReadStream::hasEnded() const {
        return !hasNext();
    }
}
