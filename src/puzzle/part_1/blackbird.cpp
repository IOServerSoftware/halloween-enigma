#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

bool is_blackbird(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "blackbird") return true;
    if (event.msg.content.substr(prefix.length()) == "Blackbird") return true;
    if (event.msg.content.substr(prefix.length()) == "BLACKBIRD") return true;
    if (event.msg.content.substr(prefix.length()) == "black bird") return true;
    if (event.msg.content.substr(prefix.length()) == "Black bird") return true;
    if (event.msg.content.substr(prefix.length()) == "Black Bird") return true;
    if (event.msg.content.substr(prefix.length()) == "BLACK BIRD") return true;
    return false;
}

void blackbird(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 2 && is_blackbird(event)) {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```The Beatles was her favourite band.\n*Blackbird singing in the dead of night...* it went.\nAnd the blackbird asks...```\nhttps://cdn.discordapp.com/attachments/1288880397794672781/1288880443461992580/morse.wav?ex=66f6caf3&is=66f57973&hm=38a97024d548742b90456200d65c0964e5dfb6d87d426375fec6477eb2cdbf71&");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}