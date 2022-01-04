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
    SDCardScreenView& view;
};