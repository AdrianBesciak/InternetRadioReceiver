#pragma once
#include <string>
#include <vector>
#include <functional>

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

        Playlist();
        virtual ~Playlist();

        [[nodiscard]] virtual const std::vector<Entry>& getEntries() const = 0;
        virtual void update() = 0;

        [[nodiscard]] const std::function<void()> &getOnUpdated() const;
        void setOnUpdated(const std::function<void()> &onUpdated);

    protected:
        void notifyUpdated();

    private:
        std::function<void()> onUpdated;
    };
}
