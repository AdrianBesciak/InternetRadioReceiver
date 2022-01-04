#pragma once
#include <gui/containers/PeripheralStateIndicators.hpp>

class PeripheralStateIndicatorsDelegate {
public:
    virtual ~PeripheralStateIndicatorsDelegate();

    void setPeripheralState(bool ethernetState, bool sdCardState);

protected:
    virtual PeripheralStateIndicators& getPeripheralStateIndicators() = 0;
};


