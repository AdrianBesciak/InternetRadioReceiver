#ifndef MUSICCONTROLPANEL_HPP
#define MUSICCONTROLPANEL_HPP

#include <gui_generated/containers/musicControlPanelBase.hpp>

class musicControlPanel : public musicControlPanelBase
{
public:
    musicControlPanel();
    virtual ~musicControlPanel() {}

    virtual void initialize();
protected:
};

#endif // MUSICCONTROLPANEL_HPP
