
#include "../../include/dotmgr.hpp"
#include <filesystem>
#include <fstream>

std::vector<std::string> read_config() {

    std::vector<std::string> out;

    if (!fs::exists(DOT_CONFIG_PATH)) {
        printf("config.dot does not exist\n");
        return out;
    }

    std::ifstream config_file(DOT_CONFIG_PATH);

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
