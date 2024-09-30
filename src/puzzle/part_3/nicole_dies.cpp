#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

void nicole_dies(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 27) {
        increment_progress(user_progress_path, check_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Hmm...");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("There *is*, however, a compromise...");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("There is a big puzzle I want you to solve.");
    }
}