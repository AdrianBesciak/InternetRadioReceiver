#pragma once
#include <gui_generated/sdcardscreen_screen/SDCardScreenViewBase.hpp>

class SDCardScreenView : public SDCardScreenViewBase {
public:
    SDCardScreenView();

    PeripheralStateIndicators &getPeripheralStateIndicators();
    VolumePanel &getVolumePanel();
    TitleView &getTitleView();
    TimePanelSD &getTimePanel();
    ControlPanelSD &getControlPanel();
    Playlist& getPlaylist();
    ErrorDialog& getErrorDialog();
};
