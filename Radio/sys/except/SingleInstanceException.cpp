#include "SingleInstanceException.hpp"

namespace sys {
    SingleInstanceException::SingleInstanceException(const std::string &arg)
        : logic_error(arg) {}
}
