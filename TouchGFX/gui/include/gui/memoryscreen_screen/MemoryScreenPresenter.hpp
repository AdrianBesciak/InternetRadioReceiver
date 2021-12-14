#pragma once
#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MemoryScreenView;

class MemoryScreenPresenter : public touchgfx::Presenter, public ModelListener {
public:
    explicit MemoryScreenPresenter(MemoryScreenView& view);

    void activate() override;
    void deactivate() override;
    void update() override;

private:
    MemoryScreenView& view;
};
