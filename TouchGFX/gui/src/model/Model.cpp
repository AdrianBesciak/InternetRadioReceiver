#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "ApplicationModule.h"

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
    std::printf("Ethernet: %u, SD card: %u\n\r", applicationModuleInstance->getEthernetState(), applicationModuleInstance->getSdCardState());
    //if (ethernetState != applicationModuleInstance->getEthernetState())
    {
        modelListener->changeEthernetIndicator(applicationModuleInstance->getEthernetState());
    }
    //if (sdCardState != applicationModuleInstance->getSdCardState())
    {
        modelListener->changeSdCardIndicator(applicationModuleInstance->getSdCardState());
    }
}
