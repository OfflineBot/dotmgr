
#include "../../include/dotmgr.hpp"

int overwrite_theme(const char *theme_name) {

    if (!fs::exists(DOT_CONFIG_PATH)) {
        printf("config.dot not found!\n");
        return 1;
    }

    std::string theme_file = THEMES_FOLDER + std::string("/") + std::string(theme_name);
    if (!fs::exists(theme_file)) {
        printf("theme does not exist! use 'dotmgr list' to see the available themes\n");
        return 1;
    }

    std::vector<std::string> folders = read_config();
    if (folders.empty()) {
        printf("no files found in config.dot\n");
        return 1;
    }

    std::string message = "overwrite the theme with: "; message += std::string(theme_name);
    confirm_action(message);
    for (int i = 0; i < folders.size(); i++) {
        std::string folder = folders[i];

        std::string dotfiles_theme_path = THEMES_FOLDER + std::string("/") + std::string(theme_name);
        std::string system_path = STOW_PATH + folder;
        std::string theme_path = THEMES_FOLDER + std::string("/") + std::string(theme_name) + folder;



        fs::remove_all(theme_path);
        copy_item_to(system_path, theme_path);
    }

    execute_reload_script();
    return 0;
}
