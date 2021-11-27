#ifndef MODEL_HPP
#define MODEL_HPP

#include <ApplicationModule.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
private:
    bool ethernetState{false};
    bool sdCardState{false};
};

#endif // MODEL_HPP
