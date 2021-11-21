#include <iostream>
#include <memory>
#include <ApplicationModule.h>


extern "C" {
void init() {
    static std::shared_ptr<ApplicationModule> applicationModule = nullptr;
    try {
        std::cout << "Initializing module\n";
        applicationModule = std::make_shared<ApplicationModule>();
        std::cout << "Module initialized\n";
    }
    catch (std::exception &exc) {
        std::cout << "Error occurred: " << exc.what() << '\n';
    }
}
}






