#include <gui/containers/Playlist.hpp>

Playlist::Playlist()
    : itemClickedHandler(this, &Playlist::handleItemClicked)
    , onItemClicked(nullptr)
    , storedSelectedIdx(-1){
    list.setItemSelectedCallback(itemClickedHandler);
}


void Playlist::setOnItemClicked(const std::function<void(std::int16_t)> &onItemClicked) {
    this->onItemClicked = onItemClicked;
}


void Playlist::setEntries(const std::vector<std::string>& entries) {
    if (entries != storedEntries) {
        storedEntries = entries;
        storedSelectedIdx = -1;
        list.setNumberOfItems(static_cast<std::int16_t>(storedEntries.size()));
        for (std::size_t idx = 0; idx < storedEntries.size(); ++idx) {
            list.itemChanged(static_cast<std::int16_t>(idx));
        }
        list.invalidate();
    }
}

void Playlist::setSelectedIdx(std::int16_t selectedIdx) {
    if (selectedIdx != storedSelectedIdx) {
        list.itemChanged(std::exchange(storedSelectedIdx, selectedIdx));
        list.itemChanged(selectedIdx);
    }
}


void Playlist::listUpdateItem(ListItem &item, std::int16_t itemIndex) {
    if (itemIndex >= 0 && static_cast<std::size_t>(itemIndex) < storedEntries.size()) {
        item.setText(storedEntries[itemIndex]);
    }
    else {
        item.setText("");
    }
    item.setSelected(storedSelectedIdx == itemIndex);
}

void Playlist::handleItemClicked(std::int16_t idx) {
    if (onItemClicked != nullptr) {
        onItemClicked(idx);
    }
}
