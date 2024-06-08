
#include "../../include/dotmgr.hpp"

int save_theme(const char *theme_name) {

    if (!fs::exists(DOT_CONFIG_PATH)) {
        printf("config.dot not found!\n");
        return 1;
    }

    std::string theme_file = THEMES_FOLDER + std::string("/") + std::string(theme_name);
    if (fs::exists(theme_file)) {
        printf("theme does already exist! use 'dotmgr overwrite' to overwrite the theme with the active theme\n");
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

        fs::remove(theme_path);
        copy_item_to(system_path, theme_path);
    }

    execute_reload_script();
    return 0;
}
