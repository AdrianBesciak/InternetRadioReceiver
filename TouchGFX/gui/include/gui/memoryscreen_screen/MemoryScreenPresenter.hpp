#ifndef MEMORYSCREENPRESENTER_HPP
#define MEMORYSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MemoryScreenView;

class MemoryScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit MemoryScreenPresenter(MemoryScreenView& view);
    void update() override;

private:
    MemoryScreenView& view;
};

#endif // MEMORYSCREENPRESENTER_HPP
