#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void hallucinations(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 5 && event.msg.content.substr(prefix.length()) == "why") {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Now you know the truth about your 'golden girl'.\nYou have no such blind eye, unlike her.\nThere are things you see that I don't.\nSo tell me, who do you see in this picture?```\nhttps://cdn.discordapp.com/attachments/1288880397794672781/1288895048196292749/Screenshot_2024-09-27_at_00.08.29.png?ex=66f6d88e&is=66f5870e&hm=737bdee394ff48a7dcd3d3eb4def44cce5059ee01944fb82d7431ccdc6fbc70e&");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}