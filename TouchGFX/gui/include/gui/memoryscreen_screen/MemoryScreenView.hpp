#ifndef MEMORYSCREENVIEW_HPP
#define MEMORYSCREENVIEW_HPP

#include <gui_generated/memoryscreen_screen/MemoryScreenViewBase.hpp>
#include <gui/memoryscreen_screen/MemoryScreenPresenter.hpp>

class MemoryScreenView : public MemoryScreenViewBase
{
public:
    MemoryScreenView();
    virtual ~MemoryScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
};

#endif // MEMORYSCREENVIEW_HPP
