#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::handleTickEvent()
{
    controls1.ethernetStateChanged(applicationModuleInstance->getEthernetState());
    controls1.sdCardStateChanged(applicationModuleInstance->getSdCardState());
    this->draw();
}