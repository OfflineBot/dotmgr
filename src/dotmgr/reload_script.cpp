
#include "../../include/dotmgr.hpp"
#include <filesystem>

void execute_reload_script() {

    if (fs::exists(RELOAD_SCRIPT_PATH)) {
        system(RELOAD_SCRIPT_PATH.c_str());
    }

}
