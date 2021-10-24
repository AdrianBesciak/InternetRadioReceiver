#include "Playlist.hpp"
#include <stdexcept>

namespace audio {
    Playlist::Entry::Entry(const std::string &name, const std::string &resource)
    : name(name)
    , resource(resource) {}

    const std::string &Playlist::Entry::getName() const {
        return name;
    }

    const std::string &Playlist::Entry::getResource() const {
        return resource;
    }
    
    Playlist::~Playlist() = default;
}
