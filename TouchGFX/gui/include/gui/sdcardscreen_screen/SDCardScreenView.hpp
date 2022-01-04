#pragma once
#include <gui_generated/sdcardscreen_screen/SDCardScreenViewBase.hpp>
#include <gui/containers/delegate/VolumePanelDelegate.hpp>
#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>
#include <gui/containers/delegate/TitleViewDelegate.hpp>
#include <gui/containers/delegate/TimePanelDelegate.hpp>
#include <gui/containers/delegate/ControlPanelSDDelegate.hpp>

class SDCardScreenView : public SDCardScreenViewBase
        , public PeripheralStateIndicatorsDelegate
        , public VolumePanelDelegate
        , public TitleViewDelegate
        , public TimePanelDelegate
        , public ControlPanelSDDelegate {
public:
    SDCardScreenView();
protected:
    PeripheralStateIndicators &getPeripheralStateIndicators() override;
    VolumePanel &getVolumePanel() override;
    TitleView &getTitleView() override;
    TimePanelInterface &getTimePanel() override;
    ControlPanelSD &getControlPanel() override;
};
