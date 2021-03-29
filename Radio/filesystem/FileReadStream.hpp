#pragma once
#include <cstddef>
#include <string>
#include <vector>

namespace filesystem {
    class FileReadStream {
    public:
        explicit FileReadStream(const std::string& filePath);
        ~FileReadStream();

        [[nodiscard]] const std::string& getFilePath() const;

        void read(void* buffer, std::size_t count);
        std::vector<std::byte> read(std::size_t count);

        void seek(std::size_t position);
        [[nodiscard]] std::size_t pos() const;

    private:
        void* handle;
        std::string filePath;
    };
}

