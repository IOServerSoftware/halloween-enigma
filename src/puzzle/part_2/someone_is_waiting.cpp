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

void someone_is_waiting(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 17) {
        if (event.msg.content.substr(prefix.length()) == "# I CANT HEAR YOU" || event.msg.content.substr(prefix.length()) == "# I CAN'T HEAR YOU"|| event.msg.content.substr(prefix.length()) == "# I CAN’T HEAR YOU") {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            event.send("```Damn! I can barely hear them!```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```We should WALK to it. Of course we'd want to so we'd know what they're saying, right?```");
        }
    }
}