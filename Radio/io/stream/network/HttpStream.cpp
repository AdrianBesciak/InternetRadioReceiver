#include "HttpStream.hpp"
#include <regex>

namespace io {
    namespace internal {
        Url::Url(const std::string &url)
            : url(url),
            protocol(),
            host(),
            path() {
            protocol = url.substr(0, url.find('/'));
            host = url.substr(protocol.size() + 2, url.find('/', protocol.size() + 2) - (protocol.size() + 2));
            path = url.substr(protocol.size() + host.size() + 2);
        }

        const std::string &Url::getUrl() const {
            return url;
        }

        const std::string &Url::getHost() const {
            return host;
        }

        const std::string &Url::getProtocol() const {
            return protocol;
        }

        const std::string &Url::getPath() const {
            return path;
        }
    }


    HttpStream::HttpStream(const std::string &url)
        : url(url)
        , stream(this->url.getHost())
        , startOffset(0) {
        stream.writeData("GET " + this->url.getPath() + "\r\n\r\n");
        std::vector<char> data(169);
        stream.readData(data.data(), data.size());
        std::size(data);
    }

    HttpStream::~HttpStream() = default;

    const std::string& HttpStream::getName() const {
        return getUrl();
    }

    const std::string& HttpStream::getUrl() const {
        return url.getUrl();
    }

    std::size_t HttpStream::read(void *buffer, std::size_t count) {
        return stream.readData(buffer, count);
    }

    std::size_t HttpStream::pos() const {
        return stream.pos() - startOffset;
    }

    std::size_t HttpStream::size() const {
        return -1;
    }

    void HttpStream::seek(std::size_t position) {
        stream.seek(position + startOffset);
    }
}
