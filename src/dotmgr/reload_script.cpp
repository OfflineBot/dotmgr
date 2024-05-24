
#include "../../include/dotmgr.hpp"
#include <filesystem>

void execute_reload_script() {
    std::string home_dir = std::getenv("HOME");
    std::string reload_script = std::string(home_dir) + std::string("/.dotfiles/reload.sh");

    if (fs::exists(reload_script)) {
        system(reload_script.c_str());
    }
}
