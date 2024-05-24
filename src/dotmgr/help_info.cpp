
#include "../../include/dotmgr.hpp"

void help_info() {

    printf("how to use dotmgr:\n");
    printf("  commands:\n");
    printf("    help                help (this text)\n");
    printf("    help-config         extra info for the config.dot file\n");
    printf("    init                initialize ~/.dotfiles + config.dot\n");
    printf("    list                list all available themes\n");
    printf("    set <theme-name>    sets the active theme\n");
    printf("        you can create a reload.sh inside ~/.dotfiles that will execute after a theme was set\n");
    printf("    save <theme-name>   create new folder with active theme\n");
    printf("    overwrite <theme-name> overwrites a theme with the active theme\n");
    printf("    remove <theme-name> removes a theme by removing the folder\n");

}

void help_config() {
    printf("how to use ~/.dotfiles/config.dot\n");
    printf("used to get the files that are going to be used for themes\n");
    printf("  examples:\n");
    printf("    # <text>            to create comments\n");
    printf("    ~/.config/hypr # <text> wont work. comment has to be at the beginning of each line\n");
    printf("    ~/.config/hypr      will copy hypr folder to ~/.dotfiles/themes/<theme_name>/hypr\n");
    printf("    ~/.config/kitty     will copy kitty folder to ~/.dotfiles/themes/<theme_name>/kitty\n");
    printf("\n");
    printf("(only ~/.config files where tested yet)\n");
}

