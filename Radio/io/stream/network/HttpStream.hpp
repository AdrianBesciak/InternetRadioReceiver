#pragma once
#include <unordered_map>
#include <io/stream/ReadStream.hpp>
#include <io/stream/network/TcpStream.hpp>

namespace io {
    namespace internal {
        class Url {
        public:
            explicit Url(const std::string &url);
            [[nodiscard]] const std::string &getUrl() const;
            [[nodiscard]] const std::string &getHost() const;
            [[nodiscard]] const std::string &getProtocol() const;
            [[nodiscard]] const std::string &getPath() const;
        private:
            std::string url;
            std::string protocol;
            std::string host;
            std::string path;
        };
    }

    class HttpStream : public ReadStream {
    public:
        explicit HttpStream(const std::string &url);
        ~HttpStream() override;
        [[nodiscard]] const std::string& getName() const override;
        [[nodiscard]] std::string getMimeType() const override;

        [[nodiscard]] const std::string& getUrl() const;
        [[nodiscard]] const std::unordered_map<std::string, std::string> &getHeaders() const;

        [[nodiscard]] std::size_t read(void *buffer, std::size_t count) override;
        [[nodiscard]] std::size_t pos() const override;
        [[nodiscard]] std::size_t size() const override;

        void seek(std::size_t position) override;

    private:
        void readHeader();
        std::unordered_map<std::string, std::string> headers;
        internal::Url url;
        TCPStream stream;
        std::size_t startOffset;
    };
}
