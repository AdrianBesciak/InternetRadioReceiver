#pragma once
#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>
#include <gui/containers/delegate/VolumePanelDelegate.hpp>
#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>
#include <gui/containers/delegate/TitleViewDelegate.hpp>
#include <gui/containers/delegate/TimePanelDelegate.hpp>
#include <gui/containers/delegate/ControlPanelRadioDelegate.hpp>

class RadioScreenView : public RadioScreenViewBase
        , public PeripheralStateIndicatorsDelegate
        , public VolumePanelDelegate
        , public TitleViewDelegate
        , public TimePanelDelegate
        , public ControlPanelRadioDelegate {
public:
    RadioScreenView();

    void fillRadioStationsList(const std::vector<model::RadioStationsListModel::Entry>& stations, std::uint8_t currentStation);

protected:
    PeripheralStateIndicators &getPeripheralStateIndicators() override;
    VolumePanel &getVolumePanel() override;
    TitleView &getTitleView() override;
    TimePanelInterface &getTimePanel() override;
    ControlPanelRadio &getControlPanel() override;
};
