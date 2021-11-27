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

void MainView::changeSdCardIndicator(bool sdState)
{
    controls1.sdCardStateChanged(sdState);
}

void MainView::changeEthernetIndicator(bool ethernetState)
{
    controls1.ethernetStateChanged(ethernetState);
}
/*
void MainView::handleTickEvent()
{
    controls1.ethernetStateChanged(applicationModuleInstance->getEthernetState());
    controls1.sdCardStateChanged(applicationModuleInstance->getSdCardState());
}*/