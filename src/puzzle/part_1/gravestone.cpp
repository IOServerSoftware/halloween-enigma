#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

bool is_death(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "death") return true;
    if (event.msg.content.substr(prefix.length()) == "Death") return true;
    if (event.msg.content.substr(prefix.length()) == "DEATH") return true;
    return false;
}

void gravestone(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 7 && is_death(event)) {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Astute. Can't say I'm surprised.\nNicole had it coming. I never really liked her.\n\nOr do I?\nThink about it. If I hate her, that might be because she rejected me.\nBut that's too stupid of a reason. Think harder.```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}