#include "../include/dotmgr.hpp"
#include <cstring>

int main(int argc, char **argv) {

    if (argc == 1) {
        help_info();
        return 0;
    }

    if (argc == 2) {
        char *argument = argv[1];
        if (std::strcmp(argument, "help") == 0) {
            help_info(); 
            return 0;
        } else if (std::strcmp(argument, "help-config") == 0) {
            help_config();
            return 0;
        } else if (std::strcmp(argument, "init") == 0) {
            init_dotfiles();
            return 0;
        } else if (std::strcmp(argument, "list") == 0) {
            list_themes();
            return 0;
        }
    } else if (argc == 3) {
        char *argument1 = argv[1];
        char *argument2 = argv[2];

        if (std::strcmp(argument1, "set") == 0) {
            set_theme(argument2);
            return 0;
        } else if (std::strcmp(argument1, "save") == 0) {
            save_theme(argument2);
            return 0;
        } else if (std::strcmp(argument1, "overwrite") == 0) {
            overwrite_theme(argument2);
            return 0;
        } else if (std::strcmp(argument1, "remove") == 0) {
            return 0;
        }
    }
    printf("Unknown arguments!\n");
    return 1;
}

