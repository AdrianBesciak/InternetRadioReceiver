#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>

PeripheralStateIndicatorsDelegate::~PeripheralStateIndicatorsDelegate() = default;

void PeripheralStateIndicatorsDelegate::setEthernetState(bool state) {
    getPeripheralStateIndicators().setEthernetState(state);
}

void PeripheralStateIndicatorsDelegate::setSdCardState(bool state) {
    getPeripheralStateIndicators().setSdCardState(state);
}
