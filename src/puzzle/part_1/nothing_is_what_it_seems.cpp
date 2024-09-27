#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void nothing_is_what_it_seems(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 4 && event.msg.content.substr(prefix.length()) == "ready") {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Good... you're starting to wake up now.\nIf Nicole was so much of a 'golden girl'... why is she so blind to the needs of others?\nYou don't see it, but I do.\nThe document below should clear up your reservations about her, if any.\n\nAnd tell me, what is the one question you ask for answers?\nIt's one word. Should be easy, right?```\nhttps://cdn.discordapp.com/attachments/1288880397794672781/1288886632727973939/nicole_case.pdf?ex=66f6d0b7&is=66f57f37&hm=f2c03d697288ce2c3ea796ef86b41bd24890504e240c10a1bc05b1c0a6aee0f0&");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}