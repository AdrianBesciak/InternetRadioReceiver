#ifndef RADIOSCREENPRESENTER_HPP
#define RADIOSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RadioScreenView;

class RadioScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit RadioScreenPresenter(RadioScreenView& view);
    void update() override;

private:
    void updateCurrentRadioStationName();
    void updateRadioStationsList();

    RadioScreenView& view;
};

#endif // RADIOSCREENPRESENTER_HPP
