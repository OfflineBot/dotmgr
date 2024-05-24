
#pragma once
#include <filesystem>
#include <string>
#include <vector>


namespace fs = std::filesystem;


int init_dotfiles();

void help_info();
void help_config();

int list_themes(void);
int set_theme(const char *theme_name);
int save_theme(const char *theme_name);
int overwrite_theme(const char *theme_name);
int remove_theme(const char *theme_name);

void execute_reload_script();
int confirm_action(const std::string what_to_do);
std::string replace_string_by(const std::string &src, const std::string &search, const std::string &replace);
void copy_item_to(const fs::path &source, const fs::path &target);

std::vector<std::string> read_config();
