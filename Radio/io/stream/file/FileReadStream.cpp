#include "FileReadStream.hpp"
#include <init/sdinit.hpp>
#include <stdexcept>
#include <ff.h>

namespace io {
    FileReadStream::FileReadStream(const std::string &filePath)
        : handle(nullptr)
        , filePath(filePath) {
        init::initializeSD();

        handle = new FIL;
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        if (f_open(fileHandle, filePath.c_str(), FA_READ) != FR_OK)
            throw std::runtime_error("Failed to open file '" + filePath + "'");
    }

    FileReadStream::~FileReadStream() {
        f_close(reinterpret_cast<FIL*>(handle));
        delete reinterpret_cast<FIL*>(handle);
    }

    const std::string& FileReadStream::getName() const {
        return getFilePath();
    }

    const std::string &FileReadStream::getFilePath() const {
        return filePath;
    }

    std::size_t FileReadStream::read(void *buffer, std::size_t count) {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        UINT bytesRead = 0;
        if (f_read(fileHandle, buffer, static_cast<UINT>(count), &bytesRead) != FR_OK)
            throw std::runtime_error("Failed to read from file '" + filePath + "'");
        return static_cast<std::size_t>(bytesRead);
    }

    std::size_t FileReadStream::pos() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_tell(fileHandle));
    }

    void FileReadStream::seek(std::size_t position) {
        if (f_lseek(reinterpret_cast<FIL*>(handle), static_cast<FSIZE_t>(position)) != FR_OK)
            throw std::runtime_error("Failed to seek to " + std::to_string(position));
    }
}