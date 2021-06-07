#pragma once
#include <string>

namespace io {
    class TCPStream {
    public:
        explicit TCPStream(const std::string &host);

        ~TCPStream();
        void writeData(const std::string &data);

        [[nodiscard]] std::size_t readData(void *buffer, std::size_t count);
        [[nodiscard]] std::size_t pos() const;

        void seek(std::size_t position);

    private:
        std::string host;
        int descriptor;
        std::size_t position;
    };
}