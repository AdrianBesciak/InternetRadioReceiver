#pragma once
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RadioScreenView;

class RadioScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit RadioScreenPresenter(RadioScreenView& view);

    void activate() override;
    void deactivate() override;
    void update() override;

private:
    void updatePeripheralsState();
    void updateVolume();
    void updateTitle();
    void updateTime();
    void updatePlayerControls();
    void updatePlaylist();
    void updateError();

    RadioScreenView& view;
};

