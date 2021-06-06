#pragma once
#include <io/stream/ReadStream.hpp>

namespace io {
    class TCPStream : public ReadStream {
    public:
        ~TCPStream() override;
        [[nodiscard]] std::size_t read(void *buffer, std::size_t count) override;
        [[nodiscard]] std::size_t pos() const override;

        void seek(std::size_t position) override;
    };
}