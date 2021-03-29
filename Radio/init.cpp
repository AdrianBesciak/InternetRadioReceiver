#include <iostream>
#include <filesystem/DirectoryListing.hpp>

extern "C" {
void init() {
    filesystem::DirectoryListing listing("0:/");
    filesystem::DirectoryListing listing2("0:/");
    std::cout << listing.getFileCount() << '\n';
}
}






