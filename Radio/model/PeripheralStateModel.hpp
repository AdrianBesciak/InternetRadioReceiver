#pragma once


namespace model {
    class PeripheralStateModel {
    public:
        PeripheralStateModel();

        [[nodiscard]] bool isEthernetState() const;
        void setEthernetState(bool ethernetState);

        [[nodiscard]] bool isSdCardState() const;
        void setSdCardState(bool sdCardState);

    private:
        bool ethernetState;
        bool sdCardState;
    };
}


