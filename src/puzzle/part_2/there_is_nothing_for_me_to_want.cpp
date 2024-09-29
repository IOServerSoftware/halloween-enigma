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

void there_is_nothing_for_me_to_want(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::string safe_path = __user_progress_container(event.msg.author.id)+"_safe.txt";
    std::ifstream safe_storage(safe_path);
    std::string safe_code;
    std::getline(safe_storage, safe_code);
    safe_storage.close();

    if (current == 15) {
        if (event.msg.content.substr(prefix.length()) != safe_code) {
            return; // Do nothing
        }
        if (event.msg.content.substr(prefix.length()) == safe_code) {
            std::ifstream check_progress(user_progress_path);
            increment_progress(user_progress_path, check_progress);
        }
    }
}