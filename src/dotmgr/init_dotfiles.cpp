
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

int init_dotfiles() {

    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("Couldnt get the home directory!\n");
        return 1;
    }

    std::string dot_folder_path = std::string(home_dir) + std::string("/.dotfiles");
    std::string config_dot_path = dot_folder_path + "/config.dot";
    std::string themes_path = dot_folder_path + std::string("/themes");

    if (fs::exists(dot_folder_path)) {
        if (!fs::exists(themes_path)) {
            fs::create_directory(themes_path);
        }

        if (fs::exists(config_dot_path)) {
            printf("already initialized\n");
            return 0;
        } else {
            std::ofstream config(config_dot_path);
            if (config.is_open()) config.close();
            printf("created config.dot\n");
            return 0;
        }
    }


    try {
        fs::create_directory(dot_folder_path);
        std::ofstream config(config_dot_path);
        if (config.is_open()) config.close();
        if (!fs::exists(themes_path)) fs::create_directory(themes_path);
        printf("Successfully initialized ~/dotfiles\n");
        return 0;
    } catch (const fs::filesystem_error &e) {
        std::cout << "Failed to initialize! ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
