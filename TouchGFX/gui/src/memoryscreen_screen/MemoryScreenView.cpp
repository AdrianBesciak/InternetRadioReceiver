#include <gui/memoryscreen_screen/MemoryScreenView.hpp>

MemoryScreenView::MemoryScreenView()
{

}

void MemoryScreenView::setupScreen()
{
    MemoryScreenViewBase::setupScreen();
}

void MemoryScreenView::tearDownScreen()
{
    MemoryScreenViewBase::tearDownScreen();
}

void MemoryScreenView::handleTickEvent()
{
    controls1.ethernetStateChanged(applicationModuleInstance->getEthernetState());
    controls1.sdCardStateChanged(applicationModuleInstance->getSdCardState());
    this->draw();
}
