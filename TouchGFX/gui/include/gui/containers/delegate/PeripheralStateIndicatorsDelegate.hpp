#pragma once
#include <gui/containers/PeripheralStateIndicators.hpp>

class PeripheralStateIndicatorsDelegate {
public:
    virtual ~PeripheralStateIndicatorsDelegate();
    void setEthernetState(bool state);
    void setSdCardState(bool state);

protected:
    virtual PeripheralStateIndicators& getPeripheralStateIndicators() = 0;
};


