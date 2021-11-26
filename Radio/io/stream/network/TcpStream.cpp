#include "TcpStream.hpp"
#include <stdexcept>
#include <vector>
#include <lwip/api.h>
#include <lwip/sockets.h>

namespace io {
    namespace internal {
        ip4_addr_t getAddressFromHost(const std::string &host) {
            ip4_addr_t hostAddress;
            if (netconn_gethostbyname(host.c_str(), &hostAddress) != ERR_OK) {
                throw std::runtime_error("Failed to resolve host '" + host + "'");
            }
            return hostAddress;
        }

        int openSocket(const std::string &host, std::uint16_t port) {
            ip4_addr_t hostAddress = getAddressFromHost(host);
            char addressString[16];
            strcpy(addressString, ip4addr_ntoa(&hostAddress));

            sockaddr_in socket = {};
            socket.sin_family = AF_INET;
            socket.sin_port = lwip_htons(port);
            lwip_inet_pton(socket.sin_family, addressString, &(socket.sin_addr));

            int descriptor = lwip_socket(socket.sin_family, SOCK_STREAM, 0);
            if (lwip_connect(descriptor, (struct sockaddr *)&socket, sizeof(socket)) != 0) {
                throw std::runtime_error("Error contacting remote host '" + host + "'");
            }
            return descriptor;
        }

        void closeSocket(int descriptor) {
            lwip_shutdown(descriptor, SHUT_RDWR);
            lwip_close(descriptor);
        }
    }

    TCPStream::TCPStream(const std::string &host, std::uint16_t port)
        : host(host)
        , descriptor(-1)
        , position(0) {
        descriptor = internal::openSocket(host, port);
    }

    TCPStream::~TCPStream() {
        internal::closeSocket(descriptor);
    }

    void TCPStream::writeData(const std::string &data) {
        ssize_t count = lwip_write(descriptor, data.c_str(), data.size());
        if (count < 0 || std::size_t(count) != data.size()) {
            throw std::runtime_error("Failed to write data to '" + host + "'");
        }
    }

    std::size_t TCPStream::readData(void *buffer, std::size_t count) {
        std::size_t totalRead = 0;
        while (totalRead != count) {
            ssize_t readCount = lwip_recv(descriptor, reinterpret_cast<char*>(buffer) + totalRead, count - totalRead, MSG_MORE);
            if (readCount < 0) {
                throw std::runtime_error("Failed to read data from '" + host + "' - " + std::to_string(errno));
            }
            totalRead += readCount;
        }
        position += totalRead;
        return totalRead;
    }

    std::size_t TCPStream::pos() const {
        return position;
    }

    void TCPStream::seek(std::size_t position) {
        if (position < this->position) {
            throw std::runtime_error("Can't seek backwards with sockets");
        }
        if (position == this->position) {
            return;
        }
        std::vector<std::byte> data(position - this->position);
        std::size_t count = readData(data.data(), data.size());
        if (count != data.size()) {
            throw std::runtime_error("Failed to seek to position " + std::to_string(position));
        }
    }
}
