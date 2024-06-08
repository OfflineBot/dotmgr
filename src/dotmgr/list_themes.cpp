
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <iostream>

int list_themes() {


    if (!fs::exists(THEMES_FOLDER)) {
        printf("~/.dotmgr does not exist");
        return 1;
    }

    try {
        for (const auto &entry : fs::directory_iterator(THEMES_FOLDER)) {
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
