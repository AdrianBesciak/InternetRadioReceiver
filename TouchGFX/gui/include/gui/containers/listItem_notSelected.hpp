#ifndef LISTITEM_NOTSELECTED_HPP
#define LISTITEM_NOTSELECTED_HPP

#include <gui_generated/containers/listItem_notSelectedBase.hpp>

class listItem_notSelected : public listItem_notSelectedBase
{
public:
    listItem_notSelected();
    virtual ~listItem_notSelected() {}

    virtual void initialize();
protected:
};

#endif // LISTITEM_NOTSELECTED_HPP
