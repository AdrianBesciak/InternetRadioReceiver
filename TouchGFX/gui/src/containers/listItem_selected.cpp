#include <gui/containers/listItem_selected.hpp>

listItem_selected::listItem_selected()
{

}

void listItem_selected::initialize()
{
    listItem_selectedBase::initialize();
}

void listItem_selected::setName(std::string name)
{
    static Unicode::UnicodeChar buff[20];
    Unicode::strncpy(buff, name.c_str(), name.size());
    Unicode::snprintf(FileNameBuffer, 20, "%s", buff);
    FileName.invalidate();
}