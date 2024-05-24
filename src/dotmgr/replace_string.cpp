
#include "../../include/dotmgr.hpp"

std::string replace_string_by(const std::string &src, const std::string &search, const std::string &replace) {
    std::string result = src;
    size_t pos = 0;
    while ((pos = result.find(search, pos)) != std::string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }

    return result;
    return "";
}
