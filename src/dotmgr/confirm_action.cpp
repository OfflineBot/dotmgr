
#include "../../include/dotmgr.hpp"
#include <iostream>

// are you sure you want to: 
int confirm_action(const std::string what_to_do) {
    std::string input;
    std::cout << "Are you sure you want to " << what_to_do << "? (y/n): ";
    std::cin >> input;

    if (input == "y") return 0;
    else if (input == "n") return 1;

    input = "";
    std::cout << "Invalid input! Try again (y/n): ";
    std::cin >> input;

    if (input == "y") return 0;
    else if (input == "n") {
        std::cout << "Invalid input!" << std::endl; 
        return 1;
    } else return 1;

}
