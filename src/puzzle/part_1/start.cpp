#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void puzzle_init(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    if (!fs::exists(user_progress_path)) {
        std::ofstream progress_file(user_progress_path);
        progress_file << "0";
        progress_file.close();
    }
    int current = read_progress(user_progress_path);
    if (current == 0) {
        // User has started puzzle
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.reply("```And so you finally come.```");
    } else return;
}