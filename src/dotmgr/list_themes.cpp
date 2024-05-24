
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <iostream>

int list_themes() {

    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("couldnt get home directory\n");
        return 1;
    }

    std::string dot_files_folder = std::string(home_dir) + std::string("/.dotfiles/themes");
    if (!fs::exists(dot_files_folder)) {
        printf("~/.dotfiles does not exist");
        return 1;
    }

    try {
        for (const auto &entry : fs::directory_iterator(dot_files_folder)) {
            if (entry.is_directory()) {
                std::cout << entry.path().filename() << std::endl;
            }
        }
        return 0;
    } catch (const fs::filesystem_error &e) {
        std::cout << "Failed to list directory themes: " << e.what() << std::endl;
        return 1;
    }

}
