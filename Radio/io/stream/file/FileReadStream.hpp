#pragma once
#include <io/stream/ReadStream.hpp>
#include <string>
#include <vector>

namespace io {
    class FileReadStream : public ReadStream{
    public:
        explicit FileReadStream(const std::string& filePath);
        ~FileReadStream() override;
        const std::string &getName() const override;

        [[nodiscard]] const std::string& getFilePath() const;

        [[nodiscard]] std::size_t read(void* buffer, std::size_t count) override;
        [[nodiscard]] std::size_t pos() const override;
        [[nodiscard]] std::size_t size() const override;

        void seek(std::size_t position) override;

    private:
        void* handle;
        std::string filePath;
    };
}

