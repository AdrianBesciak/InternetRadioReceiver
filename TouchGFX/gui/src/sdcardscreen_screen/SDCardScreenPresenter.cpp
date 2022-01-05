#include <gui/sdcardscreen_screen/SDCardScreenPresenter.hpp>
#include <gui/sdcardscreen_screen/SDCardScreenView.hpp>

SDCardScreenPresenter::SDCardScreenPresenter(SDCardScreenView& view)
    : view(view) {}

void SDCardScreenPresenter::activate() {
    controller::PlayerVolumeController &playerVolumeController = applicationController->getPlayerVolumeController();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked([&] { playerVolumeController.increaseVolume();});
    volumePanel.setOnVolumeMinusClicked([&] { playerVolumeController.decreaseVolume();});

    controller::ErrorController &errorController = applicationController->getErrorController();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested([&] { errorController.clearError(); });

    controller::PlayerSDCardController &playerSdCardController = applicationController->getPlayerSdCardController();
    Playlist& playlist = view.getPlaylist();
    ControlPanelSD &controlPanel = view.getControlPanel();
    playlist.setOnItemClicked([&](auto idx) { playerSdCardController.playFromPlaylist(static_cast<std::size_t>(idx));});
    controlPanel.setOnPlayClicked([&] { playerSdCardController.play(); });
    controlPanel.setOnStopClicked([&] { playerSdCardController.stop(); });
    controlPanel.setOnPauseClicked([&] { playerSdCardController.pause(); });
    controlPanel.setOnFastForwardClicked([&] { playerSdCardController.fastForward(); });
    controlPanel.setOnFastBackwardClicked([&] { playerSdCardController.fastBackward(); });
    controlPanel.setOnPlayNextClicked([&] { playerSdCardController.playNext(); });
    controlPanel.setOnPlayPreviousClicked([&] { playerSdCardController.playPrevious(); });
}

void SDCardScreenPresenter::deactivate() {
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked(nullptr);
    volumePanel.setOnVolumeMinusClicked(nullptr);

    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested(nullptr);

    Playlist& playlist = view.getPlaylist();
    playlist.setOnItemClicked(nullptr);

    ControlPanelSD &controlPanel = view.getControlPanel();
    controlPanel.setOnPlayClicked(nullptr);
    controlPanel.setOnStopClicked(nullptr);
    controlPanel.setOnPauseClicked(nullptr);
    controlPanel.setOnFastForwardClicked(nullptr);
    controlPanel.setOnFastBackwardClicked(nullptr);
    controlPanel.setOnPlayNextClicked(nullptr);
    controlPanel.setOnPlayPreviousClicked(nullptr);
}

void SDCardScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
    updateTitle();
    updateTime();
    updatePlayerControls();
    updatePlaylist();
    updateError();
}

void SDCardScreenPresenter::updatePeripheralsState() {
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    PeripheralStateIndicators &peripheralStateIndicators = view.getPeripheralStateIndicators();
    peripheralStateIndicators.setEthernetState(peripheralStateModel.isEthernetState());
    peripheralStateIndicators.setSdCardState(peripheralStateModel.isSdCardState());
}

void SDCardScreenPresenter::updateVolume() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setVolume(playerModel.getVolume());
}

void SDCardScreenPresenter::updateTitle() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    TitleView &titleView = view.getTitleView();
    titleView.setTitle(playerModel.getSDCardTitle());
}

void SDCardScreenPresenter::updateTime() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    TimePanelSD &timePanel = view.getTimePanel();
    timePanel.setTime(playerModel.getSDCardProgressCurrent(), playerModel.getSDCardProgressTotal());
}

void SDCardScreenPresenter::updatePlayerControls() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    ControlPanelSD &controlPanel = view.getControlPanel();
    bool pauseVisible = playerModel.getMode() == model::PlayerModel::Mode::SD &&
                        playerModel.getState() == audio::AudioPlayer::State::PLAYING;
    bool playVisible = !pauseVisible;
    controlPanel.setPlayVisible(playVisible);
    controlPanel.setPauseVisible(pauseVisible);
}

void SDCardScreenPresenter::updatePlaylist() {
    const model::PlaylistModel &playlistModel = applicationModel->getPlayerModel().getSdCardPlaylist();
    Playlist& playlist = view.getPlaylist();
    playlist.setEntries(playlistModel.getTitles());
    playlist.setSelectedIdx(static_cast<std::int16_t>(playlistModel.getCurrentEntryIndex()));
}

void SDCardScreenPresenter::updateError() {
    const model::ErrorModel &errorModel = applicationModel->getErrorModel();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setErrorMessage(errorModel.getErrorMessage());
}
