#ifndef RADIOSCREENVIEW_HPP
#define RADIOSCREENVIEW_HPP

#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>

class RadioScreenView : public RadioScreenViewBase {
public:
    RadioScreenView();
    controls& getControls();

    void setTitle(const std::string &title);
    void setPlayVisible(bool visible);
    void setStopVisible(bool visible);

    void fillRadioStationsList(const std::vector<model::Entry>& stations, const uint8_t currentStation);
private:
    std::string title;
};

#endif // RADIOSCREENVIEW_HPP
