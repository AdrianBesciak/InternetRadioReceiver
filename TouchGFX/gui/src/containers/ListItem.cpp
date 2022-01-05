#include <gui/containers/ListItem.hpp>

ListItem::ListItem()
    : storedText()
    , storedSelected(false) {}

void ListItem::setText(const std::string &text) {
    static Unicode::UnicodeChar buff[ITEMTEXT_SIZE];
    if (text != storedText) {
        storedText = text;
        Unicode::strncpy(buff, storedText.c_str(), ITEMTEXT_SIZE);
        Unicode::snprintf(itemTextBuffer, ITEMTEXT_SIZE, "%s", buff);
        itemText.invalidate();
    }
}

void ListItem::setSelected(bool selected) {
    if (selected != storedSelected) {
        storedSelected = selected;
        if (storedSelected) {
            itemTextBox.setColor(0xff303030);
            itemTextBox.setBorderColor(0xff101010);
        }
        else {
            itemTextBox.setColor(0xff000000);
            itemTextBox.setBorderColor(0xffffffff);
        }
        itemTextBox.invalidate();
    }
}
