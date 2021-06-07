#include "TcpStream.hpp"

namespace io {
    TCPStream::~TCPStream() {

    }

    std::size_t TCPStream::read(void *buffer, std::size_t count) {
        (void) buffer;
        (void) count;
        return 0;
    }

    std::size_t TCPStream::pos() const {
        return 0;
    }

    void TCPStream::seek(std::size_t position) {
        (void) position;
    }
}