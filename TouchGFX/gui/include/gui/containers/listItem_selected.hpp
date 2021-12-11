#ifndef LISTITEM_SELECTED_HPP
#define LISTITEM_SELECTED_HPP

#include <gui_generated/containers/listItem_selectedBase.hpp>

class listItem_selected : public listItem_selectedBase
{
public:
    listItem_selected();
    virtual ~listItem_selected() {}

    virtual void initialize();

    void setName(std::string name);
protected:
};

#endif // LISTITEM_SELECTED_HPP
