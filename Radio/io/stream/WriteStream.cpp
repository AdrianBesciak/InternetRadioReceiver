#include "WriteStream.hpp"
#include <stdexcept>

namespace io {
    WriteStream::~WriteStream() = default;

    void WriteStream::writeExact(const void *buffer, std::size_t count) {
        std::size_t writeCount = write(buffer, count);
        if (writeCount != count)
            throw std::runtime_error("Wrote " + std::to_string(writeCount) + " bytes instead of " + std::to_string(count));
    }

    std::size_t WriteStream::write(const std::vector<std::byte> &buffer) {
        return write(buffer.data(), buffer.size());
    }

    void WriteStream::writeExact(const std::vector<std::byte> &buffer) {
        writeExact(buffer.data(), buffer.size());
    }

    void WriteStream::writeLine(const std::string &line) {
        static const char END='\n';
        writeExact(line.data(), line.size());
        writeExact(&END, 1);
    }
}
