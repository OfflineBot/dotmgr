
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <fstream>

std::vector<std::string> read_config() {
    char *home_path = std::getenv("HOME");
    std::string dot_config_file = std::string(home_path) + std::string("/.dotfiles/config.dot");

    std::vector<std::string> out;

    if (!fs::exists(dot_config_file)) {
        printf("config.dot does not exist\n");
        return out;
    }

    std::ifstream config_file(dot_config_file);

    std::string line;
    if (config_file.is_open()) {
        while (std::getline(config_file, line)) {
            if (line[0] == '#') continue;
            else if (line.empty()) continue;
            out.push_back(line);
        }
    }

    return out;
}
