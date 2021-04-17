#include "DirectoryListing.hpp"
#include <filesystem/sdinit.hpp>
#include <stdexcept>
#include <ff.h>

namespace filesystem {
    DirectoryListing::DirectoryListing(const std::string &directory)
        : fileNames()
        , filePaths() {
        initializeSD();
        static DIR dir;
        static FILINFO fileInfo;

        if (f_opendir(&dir, directory.c_str()) != FR_OK)
            throw std::runtime_error("Failed to open directory '" + directory + "'");

        for(;;) {
            FRESULT result;
            if ((result = f_readdir(&dir, &fileInfo)) != FR_OK) {
                f_closedir(&dir);
                throw std::runtime_error("Failed to read directory contents of '" + directory + "'");
            }

            if (fileInfo.fname[0] == '\0')
                break;

            fileNames.emplace_back(fileInfo.fname);
            if (directory.back() == '/')
                filePaths.emplace_back(directory + fileInfo.fname);
            else
                filePaths.emplace_back(directory + "/" + fileInfo.fname);
        }
        f_closedir(&dir);
    }

    const std::string &DirectoryListing::getFileNameAt(std::size_t idx) const {
        return fileNames[idx];
    }

    const std::string &DirectoryListing::getFilePathAt(std::size_t idx) const {
        return filePaths[idx];
    }

    const std::vector<std::string> &DirectoryListing::getFileNames() const {
        return fileNames;
    }

    const std::vector<std::string> &DirectoryListing::getFilePaths() const {
        return filePaths;
    }

    std::size_t DirectoryListing::getFileCount() const noexcept {
        return fileNames.size();
    }
}