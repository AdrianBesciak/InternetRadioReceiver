#pragma once
#include <string>
#include <vector>

namespace audio {
    class Playlist {
    public:
        class Entry {
        public:
            Entry(const std::string &name, const std::string &resource);
            [[nodiscard]] const std::string &getName() const;
            [[nodiscard]] const std::string &getResource() const;
        private:
            std::string name;
            std::string resource;
        };
        
        virtual ~Playlist();
        [[nodiscard]] virtual const std::vector<Entry>& getEntries() const = 0;
    };
}
