#pragma once
#include <gui_generated/containers/controlsBase.hpp>

class controls : public controlsBase {
public:
    controls();
    void initialize() override;

    void setEthernetState(bool state);
    void setSdCardState(bool state);
};

