#pragma once

#include <string>

bool write_highscore(const std::string& user_name, int attempts, const std::string& filename);
bool show_highscore(const std::string& filename);