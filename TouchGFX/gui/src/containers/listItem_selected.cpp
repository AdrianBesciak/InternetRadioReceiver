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