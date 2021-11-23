#ifndef RADIOCONTROLPANEL_HPP
#define RADIOCONTROLPANEL_HPP

#include <gui_generated/containers/radioControlPanelBase.hpp>

class radioControlPanel : public radioControlPanelBase
{
public:
    radioControlPanel();
    virtual ~radioControlPanel() {}

    virtual void initialize();
protected:
};

#endif // RADIOCONTROLPANEL_HPP
