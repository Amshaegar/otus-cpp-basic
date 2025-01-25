#include "handle_parameters.h"

#include <iostream>
#include <string>

bool do_we_need_only_show_highscores(int argc, char* argv[]) {
    if (argc == 2) {
        std::string parameter{argv[1]};
        if (parameter == "-table") {
            return true;
        }
    }
    return false;
}

int get_random_max(int argc, char* argv[]) {
    int random_max {100};

    if (argc >= 2) {
        std::string arg1_value{argv[1]};
        if (arg1_value == "-max") {
            if (argc < 3) {
                std::cout << "Wrong usage! The argument '-max' requires some value! Will be used default value" << std::endl;
                return random_max;
            }
            random_max = std::stoi(argv[2]);
        }
    }

    return random_max;
}