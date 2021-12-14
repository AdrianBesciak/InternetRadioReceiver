#pragma once
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainView;

class MainPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit MainPresenter(MainView& view);
    void update() override;

private:
    MainView& view;
};
