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
    char tempName[] = "RMF FM\0";
    static Unicode::UnicodeChar buff[20];
    Unicode::strncpy(buff, tempName, 7);
    Unicode::snprintf(FileNameBuffer, 7, "%s", buff);
    FileName.invalidate();
}