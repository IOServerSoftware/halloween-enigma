#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

bool is_myself(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "myself") return true;
    if (event.msg.content.substr(prefix.length()) == "Myself") return true;
    if (event.msg.content.substr(prefix.length()) == "MYSELF") return true;
    return false;
}

void forgotten(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 9 && is_myself(event)) {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Hmm...\n\nYou're ready to access the inner workings of what is going on with your precious Nicole.\n...if you can decrypt the following stream, that is.\n\n[KEYSTREAM: TEARS]\n[BEGIN ENCRYPTED STREAM]\nBRIKATXIFF: VVERLX YSVJ TGCFMGX AEV TYTF-DHKIE SYXEI KNGCVKL.\n[END ENCRYPTED STREAM]```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}