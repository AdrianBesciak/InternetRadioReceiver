#ifndef MAINPRESENTER_HPP
#define MAINPRESENTER_HPP

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

#endif // MAINPRESENTER_HPP
