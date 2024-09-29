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

void where_is_she(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 23) {
        increment_progress(user_progress_path, check_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("What?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("You want to know? I don't even know anymore?\nYes. I don't even know anymore, you idiot!");
    }
}