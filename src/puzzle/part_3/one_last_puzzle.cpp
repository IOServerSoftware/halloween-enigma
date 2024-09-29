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

void one_last_puzzle(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 28) {
        increment_progress(user_progress_path, check_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Are you considering it...?");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("I warn you, it is a very involved one.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("You will need to know how to decrypt my ciphers.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Tell me when you're ready.");
    }
}