
#include "../../include/dotmgr.hpp"
#include <filesystem>

int set_theme(const char *theme_name) {

    char *home_dir = std::getenv("HOME");
    std::string home_dir_string = std::string(home_dir);
    std::string config_dot_path = home_dir_string + std::string("/.dotfiles/config.dot");

    if (!fs::exists(config_dot_path)) {
        printf("config.dot not found!\n");
        return 1;
    }

    std::string theme_file = home_dir_string + std::string("/.dotfiles/themes/") + std::string(theme_name);
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
        std::string dotfiles_theme_path = home_dir_string + std::string("/.dotfiles/themes/") + std::string(theme_name);
        std::string system_path = replace_string_by(folder, "~", home_dir_string);
        std::string theme_path = replace_string_by(folder, "~/.config", dotfiles_theme_path);

        if (!fs::exists(theme_path)) continue;
        fs::remove_all(system_path);
        copy_item_to(theme_path, system_path);
    }

    execute_reload_script();
    return 0;
}

