#include <gui/radioscreen_screen/RadioScreenView.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <model/PlaylistModel.hpp>

RadioScreenPresenter::RadioScreenPresenter(RadioScreenView& view)
    : view(view) {}


void RadioScreenPresenter::activate() {
    controller::PlayerVolumeController &playerVolumeController = applicationController->getPlayerVolumeController();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked([&] { playerVolumeController.increaseVolume();});
    volumePanel.setOnVolumeMinusClicked([&] { playerVolumeController.decreaseVolume();});

    controller::ErrorController &errorController = applicationController->getErrorController();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested([&] { errorController.clearError(); });

    controller::PlayerRadioController &playerRadioController = applicationController->getPlayerRadioController();
    Playlist& playlist = view.getPlaylist();
    ControlPanelRadio &controlPanel = view.getControlPanel();
    playlist.setOnItemClicked([&](auto idx) { playerRadioController.playFromPlaylist(static_cast<std::size_t>(idx));});
    controlPanel.setOnPlayClicked([&] { playerRadioController.play(); });
    controlPanel.setOnStopClicked([&] { playerRadioController.stop(); });
}

void RadioScreenPresenter::deactivate() {
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked(nullptr);
    volumePanel.setOnVolumeMinusClicked(nullptr);

    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested(nullptr);

    Playlist& playlist = view.getPlaylist();
    playlist.setOnItemClicked(nullptr);

    ControlPanelRadio &controlPanel = view.getControlPanel();
    controlPanel.setOnPlayClicked(nullptr);
    controlPanel.setOnStopClicked(nullptr);
}

void RadioScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
    updateTitle();
    updateTime();
    updatePlayerControls();
    updatePlaylist();
    updateError();
}

void RadioScreenPresenter::updatePeripheralsState() {
    const model::PeripheralStateModel &peripheralStateModel = applicationModel->getPeripheralStateModel();
    PeripheralStateIndicators &peripheralStateIndicators = view.getPeripheralStateIndicators();
    peripheralStateIndicators.setEthernetState(peripheralStateModel.isEthernetState());
    peripheralStateIndicators.setSdCardState(peripheralStateModel.isSdCardState());
}

void RadioScreenPresenter::updateVolume() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setVolume(playerModel.getVolume());
}

void RadioScreenPresenter::updateTitle() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    TitleView &titleView = view.getTitleView();
    titleView.setTitle(playerModel.getRadioTitle());
}

void RadioScreenPresenter::updateTime() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    TimePanelRadio &timePanel = view.getTimePanel();
    timePanel.setTime(playerModel.getRadioProgressCurrent(), playerModel.getRadioProgressTotal());
}

void RadioScreenPresenter::updatePlayerControls() {
    const model::PlayerModel &playerModel = applicationModel->getPlayerModel();
    ControlPanelRadio &controlPanel = view.getControlPanel();
    bool stopVisible = playerModel.getMode() == model::PlayerModel::Mode::RADIO &&
            playerModel.getState() == audio::AudioPlayer::State::PLAYING;
    bool playVisible = !stopVisible;
    controlPanel.setPlayVisible(playVisible);
    controlPanel.setStopVisible(stopVisible);
}

void RadioScreenPresenter::updatePlaylist() {
    const model::PlaylistModel &playlistModel = applicationModel->getPlayerModel().getRadioPlaylist();
    Playlist& playlist = view.getPlaylist();
    playlist.setEntries(playlistModel.getTitles());
    playlist.setSelectedIdx(static_cast<std::int16_t>(playlistModel.getCurrentEntryIndex()));
}

void RadioScreenPresenter::updateError() {
    const model::ErrorModel &errorModel = applicationModel->getErrorModel();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setErrorMessage(errorModel.getErrorMessage());
}
