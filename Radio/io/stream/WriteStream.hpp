#pragma once
#include <string>
#include <vector>

namespace io {
    class WriteStream {
    public:
        ~WriteStream();
        [[nodiscard]] virtual const std::string& getName() const = 0;

        [[nodiscard]] virtual std::size_t write(const void* buffer, std::size_t count) = 0;
        void writeExact(const void* buffer, std::size_t count);

        [[nodiscard]] std::size_t write(const std::vector<std::byte> &buffer);
        void writeExact(const std::vector<std::byte> &buffer);
        void writeLine(const std::string &line);

        [[nodiscard]] virtual std::size_t pos() const = 0;
        [[nodiscard]] virtual std::size_t size() const = 0;
        virtual void seek(std::size_t position) = 0;
    };
}
