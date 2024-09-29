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

void why_would_you_do_this(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 24) {
        increment_progress(user_progress_path, check_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Why would *I* do this?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("# Why the FUCK would *I* do this?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Boredom isn't enough of a reason for you?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("# I DON'T FUCKING LIKE HER.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("That is why.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Happy?");
    }
}