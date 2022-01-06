#pragma once
#include <io/stream/ReadStream.hpp>
#include <string>
#include <vector>

namespace io {
    class FileReadStream : public ReadStream {
    public:
        explicit FileReadStream(const std::string& filePath, bool createIfNotExists = false);
        ~FileReadStream() override;
        [[nodiscard]] const std::string &getName() const override;
        [[nodiscard]] std::string getMimeType() const override;

        bool isRandomAccess() const override;

        [[nodiscard]] const std::string& getFilePath() const;

        [[nodiscard]] std::size_t read(void* buffer, std::size_t count) override;
        [[nodiscard]] std::size_t pos() const override;
        [[nodiscard]] std::size_t size() const override;

        void seek(std::size_t position) override;

    protected:
        void throwReadException(const std::string &message) override;

    private:
        void* handle;
        std::string filePath;
    };
}

