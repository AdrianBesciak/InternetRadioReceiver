#pragma once
#include <string>
#include <vector>

namespace io {
    class ReadStream {
    public:
        virtual ~ReadStream();
        virtual const std::string& getName() const = 0;

        [[nodiscard]] virtual std::size_t read(void* buffer, std::size_t count) = 0;

        void readExact(void* buffer, std::size_t count);

        [[nodiscard]] std::vector<std::byte> read(std::size_t count);
        [[nodiscard]] std::vector<std::byte> readExact(std::size_t count);

        [[nodiscard]] virtual std::size_t pos() const = 0;
        virtual void seek(std::size_t position) = 0;
    };
}