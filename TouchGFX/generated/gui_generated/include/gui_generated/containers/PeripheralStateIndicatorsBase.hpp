/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PERIPHERALSTATEINDICATORSBASE_HPP
#define PERIPHERALSTATEINDICATORSBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>

class PeripheralStateIndicatorsBase : public touchgfx::Container
{
public:
    PeripheralStateIndicatorsBase();
    virtual ~PeripheralStateIndicatorsBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image sdUnmountedInd;
    touchgfx::Image sdMountedInd;
    touchgfx::Image ethernetConnectedInd;
    touchgfx::Image ethernetDisconnectedInd;

private:

};

#endif // PERIPHERALSTATEINDICATORSBASE_HPP