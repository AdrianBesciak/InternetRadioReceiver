#pragma once
#include <gui_generated/containers/PeripheralStateIndicatorsBase.hpp>

class PeripheralStateIndicators : public PeripheralStateIndicatorsBase {
public:
    PeripheralStateIndicators();
    void initialize() override;

    void setEthernetState(bool state);
    void setSdCardState(bool state);
};

