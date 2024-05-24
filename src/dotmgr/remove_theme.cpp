
#include "../../include/dotmgr.hpp"
#include <filesystem>

int remove_theme(const char *theme_name) {

    std::string message = "remove the theme: ";
    message += std::string(theme_name); message += std::string("?");

    if (confirm_action(message) == 1) {
        return 1;
    }

    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("couldnt get home directory\n");
        return 1;
    }

    std::string dot_folder_path = std::string(home_dir) + std::string("/.dotfiles") + std::string(theme_name);

    if (fs::exists(dot_folder_path) && fs::is_directory(dot_folder_path)) {
        fs::remove_all(dot_folder_path);
        return 0;
    } else {
        printf("theme does not exist\n");
        return 1;
    }
}
