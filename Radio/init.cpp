#include <iostream>
#include <memory>
#include <ApplicationModule.h>


extern "C" {
void init() {
    static std::shared_ptr<ApplicationModule> applicationModule = nullptr;
    try {
        applicationModule = std::make_shared<ApplicationModule>();
    }
    catch (std::exception &exc) {
        std::cout << "Error occurred: " << exc.what() << '\n';
    }
}
}






