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


    Playlist::Playlist()
            : onUpdated(nullptr) {}
    
    Playlist::~Playlist() = default;

    void Playlist::notifyUpdated() {
        if (onUpdated != nullptr) {
            onUpdated();
        }
    }

    const std::function<void()> &Playlist::getOnUpdated() const {
        return onUpdated;
    }

    void Playlist::setOnUpdated(const std::function<void()> &onUpdated) {
        this->onUpdated = onUpdated;
    }
}
