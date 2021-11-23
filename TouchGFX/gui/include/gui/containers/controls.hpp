#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <gui_generated/containers/controlsBase.hpp>

class controls : public controlsBase
{
public:
    controls();
    virtual ~controls() {}

    virtual void initialize();
protected:
};

#endif // CONTROLS_HPP
