#include "UnimplementedException.hpp"

namespace except {

    UnimplementedException::UnimplementedException()
        : logic_error("Unimplemented yet") {}
}
