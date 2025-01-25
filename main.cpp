#include "handle_parameters.h"
#include "high_scores.h"

#include <ctime>
#include <iostream>

int generate_random_number(int random_max);


int main(int argc, char* argv[]) {
    const std::string high_scores_filename = "high_scores.txt";

    if (do_we_need_only_show_highscores(argc, argv)) {
        if (!show_highscore(high_scores_filename)) {
            return -1;
        }
        return 0;
    }

    int random_max = get_random_max(argc, argv);

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;

    std::cout << "Enter your guess:" << std::endl;

    int hidden_number {generate_random_number(random_max)};
    int current_value {0};
    int attempts {0};
    do {
        std::cin >> current_value;
        if (hidden_number < current_value) {
            std::cout << "less than " << current_value << std::endl;
        }
        else if (hidden_number > current_value) {
            std::cout << "greater than " << current_value << std::endl;
        }
        else {
            std::cout << "you win! attempts = " << attempts << std::endl;
            break;
        }

        ++attempts;

    } while(true);

    if (!write_highscore(user_name, attempts, high_scores_filename)) {
        return -1;
    }

    std::cout << "\n";

    if (!show_highscore(high_scores_filename)) {
        return -1;
    }

    return 0;
}

int generate_random_number(int random_max) {
    std::srand(std::time(nullptr));
    return std::rand() % random_max;
}