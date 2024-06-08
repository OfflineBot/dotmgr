
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <cstring>

void set_log_file(const char *theme_name) {
    std::ofstream log_file(DOT_LOG_PATH);
    if (log_file.is_open()) {
        log_file << theme_name;
        log_file.close();
    }
}

int active_theme(const char *theme_name) {
    if (!fs::exists(DOT_LOG_PATH)) { return 0; };

    std::ifstream file(DOT_LOG_PATH);
    if (file.is_open()) {
        std::string input;
        if (std::getline(file, input)) {
            if (std::strcmp(input.c_str(), theme_name) == 0) {
                file.close();
                return 1;
            } 
            file.close();
            return 0;
        }
    }
    return 0;
}

int set_theme(const char *theme_name) {

    if (active_theme(theme_name) == 1) return 1;

    if (!fs::exists(DOT_CONFIG_PATH)) {
        printf("config.dot not found!\n");
        return 1;
    }

    std::string theme_file = THEMES_FOLDER + std::string("/") + std::string(theme_name);
    if (!fs::exists(theme_file)) {
        printf("theme does not exist! use 'dotmgr list' to list available themes\n");
        return 1;
    }

    std::vector<std::string> folders = read_config();
    if (folders.empty()) {
        printf("no files found in config.dot\n");
        return 1;
    }

    for (int i = 0; i < folders.size(); i++) {
        std::string folder = folders[i];

        std::string dotfiles_theme_path = THEMES_FOLDER + std::string("/") + std::string(theme_name);
        std::string system_path = STOW_PATH + folder;
        std::string theme_path = THEMES_FOLDER + std::string("/") + std::string(theme_name) + folder;

        if (!fs::exists(theme_path)) continue;
        fs::remove_all(system_path);
        copy_item_to(theme_path, system_path);
    }

    set_log_file(theme_name);
    execute_reload_script();
    return 0;
}

