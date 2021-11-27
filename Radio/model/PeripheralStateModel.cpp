#include "PeripheralStateModel.hpp"

namespace model {
    PeripheralStateModel::PeripheralStateModel()
            : ethernetState(false)
            , sdCardState(false) {}


    bool PeripheralStateModel::isEthernetState() const {
        return ethernetState;
    }

    void PeripheralStateModel::setEthernetState(bool ethernetState) {
        PeripheralStateModel::ethernetState = ethernetState;
    }

    bool PeripheralStateModel::isSdCardState() const {
        return sdCardState;
    }

    void PeripheralStateModel::setSdCardState(bool sdCardState) {
        PeripheralStateModel::sdCardState = sdCardState;
    }
}
