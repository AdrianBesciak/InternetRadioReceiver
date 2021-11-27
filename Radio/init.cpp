#include <iostream>
#include <memory>
#include <ApplicationModule.h>

static std::shared_ptr<ApplicationModule> applicationModule = nullptr;

extern "C" {
void init() {
    try {
        applicationModule = std::make_shared<ApplicationModule>();
    }
    catch (std::exception &exc) {
        printf("%s\n", exc.what());
    }
}
}






