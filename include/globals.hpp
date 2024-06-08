
#pragma once

#include <cstdlib>
#include <string>

#define HOME_PATH std::string(std::getenv("HOME"))
#define STOW_FOLDER "/dotfiles"

#define STOW_PATH (HOME_PATH + std::string(STOW_FOLDER))
#define DOTMGR_PATH (HOME_PATH + std::string("/.dotmgr"))

#define THEMES_FOLDER (DOTMGR_PATH + std::string("/themes"))
#define DOT_CONFIG_PATH (DOTMGR_PATH + std::string("/config.dot"))
#define RELOAD_SCRIPT_PATH (DOTMGR_PATH + std::string("/reload.sh"))
#define DOT_LOG_PATH (DOTMGR_PATH + std::string(".log"))


