
#include "../../include/dotmgr.hpp"
#include <iostream>
#include <filesystem>

void copy_item_to(const fs::path &source, const fs::path &target) {

    try {
        if (!fs::exists(source)) {
            std::cout << "Item: " << source << " does not exist" << std::endl;
        }
        fs::path parent_dir = target.parent_path();
        if (!fs::exists(parent_dir)) {
            fs::create_directories(parent_dir);
        }
        fs::copy(source, target, fs::copy_options::recursive);
    } catch (fs::filesystem_error &e) {
        std::cout << "Couldnt copy item: " << e.what() << std::endl;
    }
}
