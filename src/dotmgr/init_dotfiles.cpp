
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

int init_dotfiles() {

    if (fs::exists(DOTMGR_PATH)) {
        if (!fs::exists(THEMES_FOLDER)) {
            fs::create_directory(THEMES_FOLDER);
        }

        if (fs::exists(DOT_CONFIG_PATH)) {
            printf("already initialized\n");
            return 0;
        } else {
            std::ofstream config(DOT_CONFIG_PATH);
            if (config.is_open()) config.close();
            printf("created config.dot\n");
            return 0;
        }
    }


    try {
        fs::create_directory(DOT_CONFIG_PATH);
        std::ofstream config(DOT_CONFIG_PATH);
        if (config.is_open()) config.close();
        if (!fs::exists(THEMES_FOLDER)) fs::create_directory(THEMES_FOLDER);
        printf("Successfully initialized ~/dotmgr\n");
        return 0;
    } catch (const fs::filesystem_error &e) {
        std::cout << "Failed to initialize! ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
