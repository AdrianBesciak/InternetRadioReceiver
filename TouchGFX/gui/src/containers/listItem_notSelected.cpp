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
    const static uint8_t buff_size{20};
    Unicode::UnicodeChar buff[buff_size];
    for (uint8_t i = 0; i < buff_size; i++)
    {
        buff[i] = '\0';
    }
    Unicode::strncpy(buff, name.c_str(), name.size());
    Unicode::snprintf(FileNameBuffer, buff_size, "%s", buff);
    FileName.setVisible(true);
    FileName.invalidate();
}