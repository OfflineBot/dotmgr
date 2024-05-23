
#include <fstream>
#include <iostream>
#include <iostream>
#include <cstring>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void help_info() {
    printf("use dotmgr:\n");
    printf("\n");
    printf("commands:\n");
    printf("    init                initialize ~/.dotfiles + config.dot\n");
    printf("    list                list all themes\n");
    printf("    help                help (this info)\n");
    printf("    set <theme_name>    load a theme\n");
    printf("    write <theme_name>  write active theme to destination\n");
    printf("    overwrite <theme_name> write active theme to destination\n");
    printf("    remove <theme_name> remove a theme\n");
    printf("\n");
    printf("included paths: \n");
    printf("    ~/.dotfiles\n");
}

int init_dotfiles() {
    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("couldnt get home dir!\n");
        return 1;
    }

    std::string dot_folder = "/.dotfiles";
    std::string dot_dir = std::string(home_dir) + dot_folder;

    if (fs::is_directory(dot_dir)) {
        printf("direcotry already exist\n");

        std::string config_file = "/config.dot";
        std::string conf_file = dot_dir + config_file;

        if (!fs::exists(conf_file)) {
            std::ofstream output(conf_file);
            if (output.is_open()) {
                output << "# each line represents a full path path to a config file that is going to be saved (just .config working for now (TODO))\n# ~/.config/hypr\n# /home/usrname/kitty" << std::endl;
                output.close();
            }

        }
        return 1;
    }

    try {
        fs::create_directory(dot_dir);
        std::string config_file = "/config.dot";
        std::string conf_file = dot_dir + config_file;
        if (!fs::exists(conf_file)) {
            std::ofstream output(conf_file);
            if (output.is_open()) {
                output << "# each line represents a full path path to a config file that is going to be saved (just .config working for now (TODO))\n# ~/.config/hypr\n# /home/usrname/kitty" << std::endl;
                output.close();
            }
        }
        return 0;
    } catch (const fs::filesystem_error &e) {
        std::cout << "Failed to create dir: " << e.what() << std::endl;
        return 1;
    }
}

int list_themes() {
    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("couldnt get home dir\n");
        return 1;
    }

    std::string dot_folder = "/.dotfiles";
    std::string dot_dir = std::string(home_dir) + dot_folder;

    if (!fs::exists(dot_dir)) {
        std::cout << "~/.dotfiles does not exist" << std::endl;
        return 1;
    }

    try {
        for (const auto &entry : fs::directory_iterator(dot_dir)) {
            if (entry.is_directory()) {
                std::cout << entry.path().filename() << std::endl;
            }
        }
        return 0;
    } catch (const fs::filesystem_error &e) {
        std::cout << "Failed to list directory contents: " << e.what() << std::endl;
    }
    return 1;
}

std::vector<std::string> read_config() {
    char *home = std::getenv("HOME");
    std::string config_file = "/.dotfiles/config.dot";
    std::string config = std::string(home) + config_file;

    std::ifstream file(config);

    std::string line;
    std::vector<std::string> out;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line[0] == '#') continue;
            if (line.empty()) continue;
            out.push_back(line);
        }
    }

    return out;
}

void copy_dir(const fs::path &source, const fs::path &target) {
    try {
        fs::copy(source, target, fs::copy_options::recursive);
    } catch (const fs::filesystem_error &e) {
        std::cout << "failed to copy direcotry: " << e.what() << std::endl;
    }
}

std::string replaceAll(const std::string& str, const std::string& search, const std::string& replace) {
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(search, pos)) != std::string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return result;
}

int wrong_typing_confirm_again() {
    std::string input;
    std::cout << "Unknown input please type again (y/n): ";
    std::cin >> input;

    if (input == "y") {
        return 0;
    } else {
        return 1;
    }
}

// sure u want to .......? (y/n)
int are_you_sure_to(std::string doing_what) {
    std::cout << "Are you sure you want to " << doing_what << " (y/n): ";
    std::string result;
    std::cin >> result;
    if (result == "y") {
        return 0;
    } else if (result == "n") {
        return 1;
    } else {
        if (wrong_typing_confirm_again() == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

int set_theme(char *theme) {
    char *home = std::getenv("HOME");
    std::string config_file = "/.dotfiles/config.dot";
    std::string config = std::string(home) + config_file;

    if (!fs::exists(config)) {
        printf("config.dot not found! consider running: dotmgr init\n");
        return 1;
    }

    std::string theme_file = std::string(home) + std::string("/.dotfiles/") + std::string(theme);
    if (!fs::exists(theme_file)) {
        printf("theme does not exist! consider using another name\n");
        return 1;
    } 

    std::vector<std::string> files = read_config();
    if (files.empty()) {
        std::cout << "no files selected to save in config.dot!\n";
        return 1;
    }

    for (int i = 0; i < files.size(); i++) {
        std::string origin = files[i];
        std::string home_path = std::string(std::getenv("HOME"));
        std::string dot_path = std::string(std::getenv("HOME")) + std::string("/.dotfiles/") + std::string(theme);
        std::string full = replaceAll(origin, "~", home_path);
        std::string target = replaceAll(origin, "~/.config", dot_path);
        fs::remove_all(full);
        copy_dir(target, full);
    }

    return 0;
}

 
int overwrite_theme(char *theme) {
        char *home = std::getenv("HOME");
    std::string config_file = "/.dotfiles/config.dot";
    std::string config = std::string(home) + config_file;

    if (!fs::exists(config)) {
        printf("config.dot not found! consider running: dotmgr init\n");
        return 1;
    }

    std::string theme_file = std::string(home) + std::string("/.dotfiles/") + std::string(theme);
    if (!fs::exists(theme_file)) {
        printf("theme does not exist! consider using another name\n");
        return 1;
    }

    std::string message = "override the theme: " + std::string(theme) + std::string("?");
    if (are_you_sure_to(message) == 1) {
        return 1;
    }

    std::vector<std::string> files = read_config();
    if (files.empty()) {
        std::cout << "no files selected to save in config.dot!\n";
        return 1;
    }

    for (int i = 0; i < files.size(); i++) {
        std::string origin = files[i];
        std::string home_path = std::string(std::getenv("HOME"));
        std::string dot_path = std::string(std::getenv("HOME")) + std::string("/.dotfiles/") + std::string(theme);
        std::string full = replaceAll(origin, "~", home_path);
        std::string target = replaceAll(origin, "~/.config", dot_path);
        fs::remove_all(target);
        copy_dir(full, target);
    }

    return 0;
}

 
int write_theme(char *theme) {
    char *home = std::getenv("HOME");
    std::string config_file = "/.dotfiles/config.dot";
    std::string config = std::string(home) + config_file;

    if (!fs::exists(config)) {
        printf("config.dot not found! consider running: dotmgr init\n");
        return 1;
    }

    std::string theme_file = std::string(home) + std::string("/.dotfiles/") + std::string(theme);
    if (fs::exists(theme_file)) {
        printf("theme already exist! consider using another name\n");
        return 1;
    } else {
        fs::create_directory(theme_file);
        printf("new folder at: ");
        std::cout << theme_file << std::endl;
    }

    std::vector<std::string> files = read_config();
    if (files.empty()) {
        std::cout << "no files selected to save in config.dot!\n";
        return 1;
    }

    for (int i = 0; i < files.size(); i++) {
        std::string origin = files[i];
        std::string home_path = std::string(std::getenv("HOME"));
        std::string dot_path = std::string(std::getenv("HOME")) + std::string("/.dotfiles/") + std::string(theme);
        std::string full = replaceAll(origin, "~", home_path);
        std::string target = replaceAll(origin, "~/.config", dot_path);
        copy_dir(full, target);
    }

    return 0;
}

int remove_theme(char *theme) {

    std::string message = "remove the theme: ";
    message += std::string(theme); message += std::string("?");
    if (are_you_sure_to(message) == 1) {
        return 1;
    }

    const char *home_dir = std::getenv("HOME");
    if (home_dir == nullptr) {
        printf("couldnt get home dir\n");
        return 1;
    }

    std::string dot_folder = "/.dotfiles/";
    std::string dot_dir = std::string(home_dir) + dot_folder + std::string(theme);

    if (fs::exists(dot_dir) && fs::is_directory(dot_dir)) {
        fs::remove_all(dot_dir);
        return 0;
    } else {
        printf("theme does not exist\n");
        return 1;
    }
}

int main(int argc, char **argv) {
    if (argc == 1 || argc > 3) {
        printf(" * Invalid amount of arguments * \n");
        help_info();
        return 0;
    }

    char *argument = argv[1];
    if (std::strcmp(argument, "init") == 0) {
        int out = init_dotfiles();
        if (out == 0) printf("ok\n");
    } 
    else if (std::strcmp(argument, "list") == 0) {
        int out = list_themes();
        if (out == 0) printf("ok\n");
    } 
    else if (std::strcmp(argument, "help") == 0) {
        help_info();
    } 
    else if (std::strcmp(argument, "set") == 0) {
        if (argc != 3) return 0;
        int out = set_theme(argv[2]);
        if (out == 0) printf("ok\n");
    } 
    else if (std::strcmp(argument, "write") == 0) {
        if (argc != 3) return 0;
        int out = write_theme(argv[2]);
        if (out == 0) printf("ok\n");
    } 
    else if (std::strcmp(argument, "overwrite") == 0) {
        if (argc != 3) return 0;
        int out = overwrite_theme(argv[2]);
        if (out == 0) printf("ok\n");
    }
    else if (std::strcmp(argument, "remove") == 0) {
        if (argc != 3) return 0;
        int out = remove_theme(argv[2]);
        if (out == 0) printf("ok\n");
    } else {
        printf("Invalid Argument!\nUse: 'dotmgr help' for more help\n");
    }

    return 0;
}

