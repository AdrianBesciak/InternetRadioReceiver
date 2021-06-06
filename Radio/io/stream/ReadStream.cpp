#include "ReadStream.hpp"
#include <stdexcept>
#include <iostream>

namespace io {
    ReadStream::~ReadStream() = default;

    void ReadStream::readExact(void *buffer, std::size_t count) {
        std::size_t readCount = read(buffer, count);
        if (readCount != count)
            throw std::runtime_error("Read " + std::to_string(readCount) + " bytes instead of " + std::to_string(count));
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
}
