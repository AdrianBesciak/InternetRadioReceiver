#pragma once
#include <gui_generated/containers/PlaylistBase.hpp>
#include <functional>

class Playlist : public PlaylistBase {
public:
    Playlist();

    void setOnItemClicked(const std::function<void(std::int16_t)> &onItemClicked);

    void setEntries(const std::vector<std::string>& entries);
    void setSelectedIdx(std::int16_t idx);

protected:
    void listUpdateItem(ListItem &item, std::int16_t itemIndex) override;
    void handleItemClicked(std::int16_t selectedIdx);

private:
    touchgfx::Callback<Playlist, std::int16_t> itemClickedHandler;
    std::function<void(std::int16_t)> onItemClicked;

    std::vector<std::string> storedEntries;
    std::int16_t storedSelectedIdx;
};
