
#include "../../include/dotmgr.hpp"

// prints help
void help_info() {
    printf("to use dotmgr its required to have all config files in ~/dotfiels/* like in stow\n");
    printf("to add a folder to the config.dot it must also exist in the ~/dotfiles/\n\n");
    printf("how to use dotmgr:\n");
    printf("  commands:\n");
    printf("    help                help (this text)\n");
    printf("    help-config         extra info for the config.dot file\n");
    printf("    init                initialize ~/.dotmgr + config.dot\n");
    printf("    list                list all available themes\n");
    printf("    set <theme-name>    sets the active theme\n");
    printf("        you can create a reload.sh inside ~/.dotmgr that will execute after a theme was set\n");
    printf("    write <theme-name>   create new folder with active theme\n");
    printf("    overwrite <theme-name> overwrites a theme with the active theme\n");
    printf("    remove <theme-name> removes a theme by removing the folder\n");

}

void help_config() {
    printf("how to use ~/.dotmgr/config.dot\n");
    printf("used to get the files that are going to be used for themes\n");
    printf("It pulls out of the /dotfiles folder (used by tools like STOW)\n");
    printf("  examples:\n");
    printf("    # <text>            to create comments\n");
    printf("    /.config/hypr # <text> wont work. comment has to be at the beginning of each line\n");
    printf("    /.config/hypr      will copy hypr folder to ~/.dotmgr/themes/<theme_name>/.config/hypr\n");
    printf("    /.config/kitty     will copy kitty folder to ~/.dotmgr/themes/<theme_name>/.config/kitty\n");
    printf("\n");
}

