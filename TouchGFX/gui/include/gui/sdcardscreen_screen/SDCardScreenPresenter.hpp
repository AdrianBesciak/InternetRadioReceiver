#pragma once
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SDCardScreenView;

class SDCardScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit SDCardScreenPresenter(SDCardScreenView& view);

    void activate() override;
    void deactivate() override;
    void update() override;

private:
    void updatePeripheralsState();
    void updateVolume();
    void updateTitle();
    void updateTime();
    void updatePlaylist();
    void updateError();

    SDCardScreenView& view;
};
