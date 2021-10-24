#pragma once
#include <io/stream/WriteStream.hpp>

namespace io {
    class FileWriteStream : public WriteStream {
    public:
        explicit FileWriteStream(const std::string& filePath);
        ~FileWriteStream();
        [[nodiscard]] const std::string &getName() const override;
        [[nodiscard]] const std::string& getFilePath() const;

        [[nodiscard]] std::size_t write(const void *buffer, std::size_t count) override;
        
        [[nodiscard]] std::size_t pos() const override;
        [[nodiscard]] std::size_t size() const override;

        void seek(std::size_t position) override;

    private:
        void* handle;
        std::string filePath;
    };
}
