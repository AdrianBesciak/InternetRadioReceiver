#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>

PeripheralStateIndicatorsDelegate::~PeripheralStateIndicatorsDelegate() = default;

void PeripheralStateIndicatorsDelegate::setPeripheralState(bool ethernetState, bool sdCardState) {
    getPeripheralStateIndicators().setEthernetState(ethernetState);
    getPeripheralStateIndicators().setSdCardState(sdCardState);
}
