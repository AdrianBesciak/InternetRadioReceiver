#include <gui/containers/listItem_notSelected.hpp>

#include <Unicode.hpp>

listItem_notSelected::listItem_notSelected()
{

}

void listItem_notSelected::initialize()
{
    listItem_notSelectedBase::initialize();
}

void listItem_notSelected::setName(std::string name)
{
    static Unicode::UnicodeChar buff[20];
    Unicode::strncpy(buff, name.c_str(), name.size());
    Unicode::snprintf(FileNameBuffer, 20, "%s", buff);
    FileName.invalidate();
}