#pragma once
#include <gui_generated/memoryscreen_screen/MemoryScreenViewBase.hpp>
#include <gui/containers/delegate/VolumePanelDelegate.hpp>
#include <gui/containers/delegate/PeripheralStateIndicatorsDelegate.hpp>
#include <gui/containers/delegate/TitleViewDelegate.hpp>
#include <gui/containers/delegate/TimePanelDelegate.hpp>
#include <gui/containers/delegate/ControlPanelSDDelegate.hpp>

class MemoryScreenView : public MemoryScreenViewBase
        , public PeripheralStateIndicatorsDelegate
        , public VolumePanelDelegate
        , public TitleViewDelegate
        , public TimePanelDelegate
        , public ControlPanelSDDelegate {
public:
    MemoryScreenView();

protected:
    PeripheralStateIndicators &getPeripheralStateIndicators() override;
    VolumePanel &getVolumePanel() override;
    TitleView &getTitleView() override;
    TimePanelInterface &getTimePanel() override;
    ControlPanelSD &getControlPanel() override;
};
