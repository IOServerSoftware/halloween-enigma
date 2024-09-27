#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void dead_eye(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 3 && event.msg.content.substr(prefix.length()) == "nicole") {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```That's right...\nIn the next message I'll send, a document of exposes will be laid out against Nicole, the one whose hubris led to her eventual downfall.\n\nTell me if you're ready.```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}