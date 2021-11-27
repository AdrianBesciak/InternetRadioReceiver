#ifndef MEMORYSCREENPRESENTER_HPP
#define MEMORYSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MemoryScreenView;

class MemoryScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MemoryScreenPresenter(MemoryScreenView& v);

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

    virtual ~MemoryScreenPresenter() {};

    void changeSdCardIndicator(bool sdState){}
    void changeEthernetIndicator(bool ethernetState){}

private:
    MemoryScreenPresenter();

    MemoryScreenView& view;
};

#endif // MEMORYSCREENPRESENTER_HPP
