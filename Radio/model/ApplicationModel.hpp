#pragma once
#include <model/PeripheralStateModel.hpp>

namespace model {
    class ApplicationModel {
    public:
        ApplicationModel();

        PeripheralStateModel &getPeripheralStateModel();
        [[nodiscard]] const PeripheralStateModel &getPeripheralStateModel() const;

    private:
        PeripheralStateModel peripheralStateModel;
    };
}


