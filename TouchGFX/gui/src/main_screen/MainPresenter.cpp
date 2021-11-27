#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::changeSdCardIndicator(bool sdState)
{
    std::printf("Ethernet: %u, SD card: %u\n\r", applicationModuleInstance->getEthernetState(), applicationModuleInstance->getSdCardState());
    view.changeSdCardIndicator(sdState);
}

void MainPresenter::changeEthernetIndicator(bool ethernetState)
{
    std::printf("Ethernet: %u, SD card: %u\n\r", applicationModuleInstance->getEthernetState(), applicationModuleInstance->getSdCardState());
    view.changeEthernetIndicator(ethernetState);
}
