#include "HttpStream.hpp"

namespace io {
    HttpStream::~HttpStream() {

    }

    std::size_t HttpStream::read(void *buffer, std::size_t count) {
        return 0;
    }

    std::size_t HttpStream::pos() const {
        return 0;
    }

    void HttpStream::seek(std::size_t position) {

    }
}