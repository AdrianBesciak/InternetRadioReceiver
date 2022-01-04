#pragma once
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainScreenView;

class MainScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit MainScreenPresenter(MainScreenView& view);
    void update() override;

private:
    void updatePeripheralsState();

    MainScreenView& view;
};
