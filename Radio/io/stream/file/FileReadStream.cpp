#include "FileReadStream.hpp"
#include <ff.h>
#include <io/except/open/FileOpenException.hpp>
#include <io/except/read/FileReadException.hpp>
#include <io/PeripheralChecker.hpp>

namespace io {
    FileReadStream::FileReadStream(const std::string &filePath, bool createIfNotExists)
        : handle(nullptr)
        , filePath(filePath) {
        PeripheralChecker::checkSDCard();
        handle = new FIL;
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        unsigned char mode = FA_READ | (createIfNotExists? FA_OPEN_ALWAYS : 0);
        if (f_open(fileHandle, filePath.c_str(), mode) != FR_OK)
            throw FileOpenException("Failed to open file '" + filePath + "'");
    }

    FileReadStream::~FileReadStream() {
        f_close(reinterpret_cast<FIL*>(handle));
        delete reinterpret_cast<FIL*>(handle);
    }

    const std::string& FileReadStream::getName() const {
        return getFilePath();
    }

    std::string FileReadStream::getMimeType() const {
        auto extensionStartPosition = filePath.find_last_of('.');
        if (extensionStartPosition == std::string::npos) {
            return "application/octet-stream";
        }
        std::string extension = filePath.substr(extensionStartPosition);
        if (extension == ".wav") {
            return "audio/wav";
        }
        if (extension == ".mp3") {
            return "audio/mpeg";
        }
        return "application/octet-stream";
    }

    bool FileReadStream::isRandomAccess() const {
        return true;
    }

    const std::string &FileReadStream::getFilePath() const {
        return filePath;
    }

    std::size_t FileReadStream::read(void *buffer, std::size_t count) {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        UINT bytesRead = 0;
        if (f_read(fileHandle, buffer, static_cast<UINT>(count), &bytesRead) != FR_OK) {
            throw FileReadException("Failed to read from file '" + filePath + "'");
        }

        return static_cast<std::size_t>(bytesRead);
    }

    std::size_t FileReadStream::pos() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_tell(fileHandle));
    }

    std::size_t FileReadStream::size() const {
        FIL* fileHandle = reinterpret_cast<FIL*>(handle);
        return static_cast<std::size_t>(f_size(fileHandle));
    }

    void FileReadStream::seek(std::size_t position) {
        if (f_lseek(reinterpret_cast<FIL*>(handle), static_cast<FSIZE_t>(position)) != FR_OK)
            throw FileReadException("Failed to seek to " + std::to_string(position));
    }

    void FileReadStream::throwReadException(const std::string &message) {
        throw FileReadException(message);
    }
}
