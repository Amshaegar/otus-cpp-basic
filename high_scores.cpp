#include "high_scores.h"

#include <fstream>
#include <iostream>

bool write_highscore(const std::string& user_name, int attempts, const std::string& filename) {
    std::ofstream out_file{filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
        return false;
    }

    out_file << user_name << ' ';
    out_file << attempts;
    out_file << std::endl;

    return true;
}

bool show_highscore(const std::string& filename) {
    std::ifstream in_file{filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
        return false;
    }

    std::cout << "High scores table:" << std::endl;
    std::string username;
    int high_score {0};
    while (true) {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();
        if (in_file.fail()) {
            break;
        }
        std::cout << username << '\t' << high_score << std::endl;
    }

    return true;
}