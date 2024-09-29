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

bool asked_if_not_nicole(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "that is not nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That is not nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "that is not Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That is not Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "THAT IS NOT NICOLE") return true;
    if (event.msg.content.substr(prefix.length()) == "that isn't nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That isn't nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "that isn't Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That isn't Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "THAT ISN'T NICOLE") return true;
    if (event.msg.content.substr(prefix.length()) == "that isn’t nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That isn’t nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "that isn’t Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "That isn’t Nicole") return true;
    if (event.msg.content.substr(prefix.length()) == "THAT ISN’T NICOLE") return true;
    else return false;
} 

void i_found_her_question_mark(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 20) {
        if (asked_if_not_nicole(event)) {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send(".\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n# YOU ABSOLUTE FOOL.");
        }
    }
}