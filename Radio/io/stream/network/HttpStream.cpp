#include "HttpStream.hpp"
#include <regex>
#include <io/except/read/HttpReadException.hpp>

namespace io {
    namespace internal {
        Url::Url(const std::string &url)
            : url(url)
            , protocol()
            , host()
            , port()
            , path() {
            protocol = url.substr(0, url.find('/') - 1);
            std::string hostWithPort = url.substr(protocol.size() + 3, url.find('/', protocol.size() + 3) - (protocol.size() + 3));
            auto pos = hostWithPort.find(':');
            if (pos != std::string::npos) {
                host = hostWithPort.substr(0, pos);
                port = static_cast<std::uint16_t>(std::stoi(hostWithPort.substr(pos + 1)));
            }
            else {
                host = hostWithPort;
                port = 80;
            }
            path = url.substr(protocol.size() + hostWithPort.size() + 3);
        }

        const std::string &Url::getUrl() const {
            return url;
        }

        const std::string &Url::getHost() const {
            return host;
        }

        std::uint16_t Url::getPort() const {
            return port;
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
        , stream(this->url.getHost(), this->url.getPort())
        , startOffset(0) {
        stream.writeData("GET " + this->url.getPath() + " HTTP/1.1\r\n");
        stream.writeData("Accept: audio/*\r\n");
        stream.writeData("Host: " + this->url.getHost() + "\r\n");
        stream.writeData("\r\n");
        readHeader();
    }

    HttpStream::~HttpStream() = default;

    const std::string& HttpStream::getName() const {
        return getUrl();
    }

    std::string HttpStream::getMimeType() const {
        auto it = headers.find("Content-Type");
        if (it == headers.end()) {
            return "application/octet-stream";
        }
        return it->second;
    }

    bool HttpStream::isRandomAccess() const {
        return false;
    }

    const std::string& HttpStream::getUrl() const {
        return url.getUrl();
    }

    const std::unordered_map<std::string, std::string> &HttpStream::getHeaders() const {
        return headers;
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

    void HttpStream::readHeader() {
        for (std::string line = readLine(); line != "\r"; line = readLine()) {
            line.pop_back();
            auto split = line.find(": ");
            if (split == std::string::npos) {
                continue;
            }
            std::string key = line.substr(0, split);
            std::string value = line.substr(split + 2);
            headers.insert({key, value});
            startOffset += line.size() + 2;
        }
        startOffset += 2;
    }

    void HttpStream::throwReadException(const std::string &message) {
        throw HttpReadException(message);
    }
}
