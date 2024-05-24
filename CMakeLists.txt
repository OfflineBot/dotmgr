cmake_minimum_required(VERSION 3.28)

project(dotmgr)

add_executable(dotmgr
    src/main.cpp
    
    src/dotmgr/init_dotfiles.cpp
    src/dotmgr/confirm_action.cpp
    src/dotmgr/copy_item.cpp
    src/dotmgr/help_info.cpp
    src/dotmgr/list_themes.cpp
    src/dotmgr/overwrite_theme.cpp
    src/dotmgr/read_config.cpp
    src/dotmgr/reload_script.cpp
    src/dotmgr/remove_theme.cpp
    src/dotmgr/replace_string.cpp
    src/dotmgr/save_theme.cpp
    src/dotmgr/set_theme.cpp

    )
