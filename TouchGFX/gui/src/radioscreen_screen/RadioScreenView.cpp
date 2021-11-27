#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView()
{

}

void RadioScreenView::setupScreen()
{
    RadioScreenViewBase::setupScreen();
}

void RadioScreenView::tearDownScreen()
{
    RadioScreenViewBase::tearDownScreen();
}

void RadioScreenView::handleTickEvent()
{
    controls1.ethernetStateChanged(applicationModuleInstance->getEthernetState());
    controls1.sdCardStateChanged(applicationModuleInstance->getSdCardState());
    this->draw();
}
