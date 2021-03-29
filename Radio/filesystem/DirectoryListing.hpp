#pragma once
#include <string>
#include <vector>

namespace filesystem {
    class DirectoryListing {
    public:
        explicit DirectoryListing(const std::string& directory);
        [[nodiscard]] const std::string& getFileNameAt(std::size_t idx) const;
        [[nodiscard]] const std::string& getFilePathAt(std::size_t idx) const;
        [[nodiscard]] const std::vector<std::string> &getFileNames() const;
        [[nodiscard]] const std::vector<std::string> &getFilePaths() const;
        [[nodiscard]] std::size_t getFileCount() const noexcept;
    private:
        std::vector<std::string> fileNames;
        std::vector<std::string> filePaths;
    };
}