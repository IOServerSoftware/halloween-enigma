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

void no_sense_of_self(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 18) {
        if (event.msg.content.substr(prefix.length()) == "walk" || event.msg.content.substr(prefix.length()) == "Walk"|| event.msg.content.substr(prefix.length()) == "WALK") {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Hmm... we're coming close...```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```I can feel it.```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Let's keep going?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```I know I don't make any sense, but, well...```");
        }
    }
}