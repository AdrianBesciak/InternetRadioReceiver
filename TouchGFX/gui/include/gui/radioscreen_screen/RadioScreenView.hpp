#pragma once
#include <gui_generated/radioscreen_screen/RadioScreenViewBase.hpp>

class RadioScreenView : public RadioScreenViewBase {
public:
    RadioScreenView();
    PeripheralStateIndicators &getPeripheralStateIndicators();
    VolumePanel &getVolumePanel();
    TitleView &getTitleView();
    TimePanelRadio &getTimePanel();
    ControlPanelRadio &getControlPanel();
    Playlist &getPlaylist();
};
