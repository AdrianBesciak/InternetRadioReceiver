#pragma once
#include <io/stream/ReadStream.hpp>

namespace io {
    class HttpStream : public ReadStream {
    public:
        ~HttpStream() override;

        [[nodiscard]] std::size_t read(void *buffer, std::size_t count) override;
        [[nodiscard]] std::size_t pos() const override;
        void seek(std::size_t position) override;
    };
}