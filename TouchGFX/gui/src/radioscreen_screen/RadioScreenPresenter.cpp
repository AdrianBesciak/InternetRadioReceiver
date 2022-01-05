#include <gui/radioscreen_screen/RadioScreenView.hpp>
#include <gui/radioscreen_screen/RadioScreenPresenter.hpp>
#include <model/PlaylistModel.hpp>

RadioScreenPresenter::RadioScreenPresenter(RadioScreenView& view)
    : view(view) {}


void RadioScreenPresenter::activate() {
    controller::VolumeController &volumeController = applicationController->getVolumeController();
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked([&] { volumeController.increaseVolume();});
    volumePanel.setOnVolumeMinusClicked([&] { volumeController.decreaseVolume();});

    controller::ErrorController &errorController = applicationController->getErrorController();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested([&] { errorController.clearError(); });
}

void RadioScreenPresenter::deactivate() {
    VolumePanel &volumePanel = view.getVolumePanel();
    volumePanel.setOnVolumePlusClicked(nullptr);
    volumePanel.setOnVolumeMinusClicked(nullptr);

    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setOnErrorDismissRequested(nullptr);
}

void RadioScreenPresenter::update() {
    updatePeripheralsState();
    updateVolume();
    updateTitle();
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

void RadioScreenPresenter::updatePlaylist() {
    const model::PlaylistModel &playlistModel = applicationModel->getPlayerModel().getRadioPlaylist();
    Playlist& playlist = view.getPlaylist();
    playlist.setEntries(playlistModel.getEntries());
    playlist.setSelectedIdx(static_cast<std::int16_t>(playlistModel.getCurrentEntryIndex()));
}

void RadioScreenPresenter::updateError() {
    const model::ErrorModel &errorModel = applicationModel->getErrorModel();
    ErrorDialog &errorDialog = view.getErrorDialog();
    errorDialog.setErrorMessage(errorModel.getErrorMessage());
}
