#pragma once
#include <gui_generated/containers/ListItemBase.hpp>

class ListItem : public ListItemBase {
public:
    ListItem();
    void setText(const std::string &text);
    void setSelected(bool selected);

private:
    std::string storedText;
    bool storedSelected;
};
