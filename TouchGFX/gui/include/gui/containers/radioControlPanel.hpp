#ifndef RADIOCONTROLPANEL_HPP
#define RADIOCONTROLPANEL_HPP

#include <gui_generated/containers/radioControlPanelBase.hpp>

class radioControlPanel : public radioControlPanelBase {
public:
    radioControlPanel();
    ~radioControlPanel() override;
    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);
    void handleTickEvent() override;
private:
    bool playDirty;
    bool stopDirty;

};

#endif // RADIOCONTROLPANEL_HPP
