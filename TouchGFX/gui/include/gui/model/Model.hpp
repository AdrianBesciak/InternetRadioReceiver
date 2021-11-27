#ifndef MODEL_HPP
#define MODEL_HPP

#include <ApplicationModule.h>
#include <model/ApplicationModel.hpp>

class ModelListener;

class Model {
public:
    Model();
    void bind(ModelListener* listener);
    void tick();

    [[nodiscard]] const model::ApplicationModel &getApplicationModel() const;

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
