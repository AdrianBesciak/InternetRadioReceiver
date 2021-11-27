#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <gui_generated/containers/controlsBase.hpp>

class controls : public controlsBase {
public:
    controls();
    ~controls() override;

    void initialize() override;

    void setEthernetState(bool state);
    void setSdCardState(bool state);
protected:
    void handleTickEvent() override;

private:
    bool ethernetStateDirty;
    bool sdCardStateDirty;
};

#endif // CONTROLS_HPP
