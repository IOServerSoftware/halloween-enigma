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

void you_have_got_to_stop(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 25) {
        increment_progress(user_progress_path, check_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("# I AM NOT *FUCKING* STOPPING!");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("# SHE'S BEEN ON MY NERVES FOR YEARS NOW!");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("This is justice, mind you.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("I never got mine.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("You're depriving me of it too?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Are you serious?");
    }
}