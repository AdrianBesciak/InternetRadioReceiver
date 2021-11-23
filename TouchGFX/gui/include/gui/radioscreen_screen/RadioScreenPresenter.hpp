#ifndef RADIOSCREENPRESENTER_HPP
#define RADIOSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RadioScreenView;

class RadioScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    RadioScreenPresenter(RadioScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~RadioScreenPresenter() {};

private:
    RadioScreenPresenter();

    RadioScreenView& view;
};

#endif // RADIOSCREENPRESENTER_HPP
