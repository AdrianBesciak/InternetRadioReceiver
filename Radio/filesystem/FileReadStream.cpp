#include "FileReadStream.hpp"
#include <filesystem/sdinit.hpp>
#include <stdexcept>
#include <ff.h>

namespace filesystem {
    FileReadStream::FileReadStream(const std::string &filePath)
        : handle(nullptr)
        , filePath(filePath) {
        initializeSD();

        handle = new FIL;
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        if (f_open(fileHandle, filePath.c_str(), FA_READ) != FR_OK)
            throw std::runtime_error("Failed to open file '" + filePath + "'");
    }

    FileReadStream::~FileReadStream() {
        f_close(reinterpret_cast<FIL*>(handle));
        delete reinterpret_cast<FIL*>(handle);
    }

    const std::string &FileReadStream::getFilePath() const {
        return filePath;
    }

    void FileReadStream::read(void *buffer, std::size_t count) {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        UINT bytesRead = 0;
        if (f_read(fileHandle, buffer, static_cast<UINT>(count), &bytesRead) != FR_OK)
            throw std::runtime_error("Failed to read from file '" + filePath + "'");
        if (bytesRead != count)
            throw std::runtime_error(
                    "Read " + std::to_string(bytesRead) +
                    " bytes instead of " + std::to_string(count) +
                    " from '" + filePath + "'");
    }

    std::vector<std::byte> FileReadStream::read(std::size_t count) {
        std::vector<std::byte> result(count);
        read(result.data(), count);
        return result;
    }

    void FileReadStream::seek(std::size_t position) {
        if (f_lseek(reinterpret_cast<FIL*>(handle), static_cast<FSIZE_t>(position)) != FR_OK)
            throw std::runtime_error("Failed to seek to " + std::to_string(position) + " in file '" + filePath + "'");
    }

    std::size_t FileReadStream::pos() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_tell(fileHandle));
    }
}