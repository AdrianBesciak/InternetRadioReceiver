#include <gui/sdcardscreen_screen/SDCardScreenPresenter.hpp>
#include <gui/sdcardscreen_screen/SDCardScreenView.hpp>

SDCardScreenPresenter::SDCardScreenPresenter(SDCardScreenView& view)
    : view(view) {}

void SDCardScreenPresenter::activate() {
    controller::VolumeController &volumeController = applicationController->getVolumeController();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked([&] { volumeController.increaseVolume();});
    volumePanel.setOnVolumeMinusClicked([&] { volumeController.decreaseVolume();});

    controller::ErrorController &errorController = applicationController->getErrorController();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested([&] { errorController.clearError(); });
}

void SDCardScreenPresenter::deactivate() {
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked(nullptr);
    volumePanel.setOnVolumeMinusClicked(nullptr);

    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested(nullptr);
}

void SDCardScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
    updateTitle();
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

void SDCardScreenPresenter::updatePlaylist() {
    const model::PlaylistModel &playlistModel = applicationModel->getPlayerModel().getSdCardPlaylist();
    Playlist& playlist = view.getPlaylist();
    playlist.setEntries(playlistModel.getEntries());
    playlist.setSelectedIdx(static_cast<std::int16_t>(playlistModel.getCurrentEntryIndex()));
}

void SDCardScreenPresenter::updateError() {
    const model::ErrorModel &errorModel = applicationModel->getErrorModel();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setErrorMessage(errorModel.getErrorMessage());
}
