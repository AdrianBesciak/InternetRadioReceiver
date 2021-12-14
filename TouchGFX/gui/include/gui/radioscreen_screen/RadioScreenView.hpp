#pragma once
#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>

class RadioScreenView : public RadioScreenViewBase {
public:
    RadioScreenView();

    void setOnPlayClicked(const std::function<void()> &onPlayClicked);
    void setOnStopClicked(const std::function<void()> &onStopClicked);

    void setPeripheralState(bool ethernetState, bool sdCardState);


    void setTitle(const std::string &title);
    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);

    void fillRadioStationsList(const std::vector<model::RadioStationsListModel::Entry>& stations, const uint8_t currentStation);
private:
    std::string title;
};
