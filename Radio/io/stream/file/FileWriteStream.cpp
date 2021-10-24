#include "FileWriteStream.hpp"
#include <init/sdinit.hpp>
#include <stdexcept>
#include <ff.h>

namespace io {
    FileWriteStream::FileWriteStream(const std::string &filePath)
        : handle(nullptr)
        , filePath(filePath) {
        init::initializeSD();

        handle = new FIL;
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        unsigned char mode = FA_WRITE | FA_CREATE_ALWAYS;
        if (f_open(fileHandle, filePath.c_str(), mode) != FR_OK)
            throw std::runtime_error("Failed to open file '" + filePath + "'");
    }

    FileWriteStream::~FileWriteStream() {
        f_close(reinterpret_cast<FIL*>(handle));
        delete reinterpret_cast<FIL*>(handle);
    }

    const std::string &FileWriteStream::getName() const {
        return filePath;
    }

    const std::string &FileWriteStream::getFilePath() const {
        return filePath;
    }

    std::size_t FileWriteStream::write(const void *buffer, std::size_t count) {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        UINT bytesWritten = 0;
        int res = f_write(fileHandle, buffer, static_cast<UINT>(count), &bytesWritten);
        if (res != FR_OK)
            throw std::runtime_error("Failed to write to file '" + filePath + "'");
        return static_cast<std::size_t>(bytesWritten);
    }

    std::size_t FileWriteStream::pos() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_tell(fileHandle));
    }

    std::size_t FileWriteStream::size() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_size(fileHandle));
    }
    
    void FileWriteStream::seek(std::size_t position) {
        if (f_lseek(reinterpret_cast<FIL*>(handle), static_cast<FSIZE_t>(position)) != FR_OK)
            throw std::runtime_error("Failed to seek to " + std::to_string(position));
    }
}
