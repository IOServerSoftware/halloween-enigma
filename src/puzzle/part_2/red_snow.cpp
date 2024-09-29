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

void red_snow(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 16) {
        if (event.msg.content.substr(prefix.length()) == "red" || event.msg.content.substr(prefix.length()) == "Red"|| event.msg.content.substr(prefix.length()) == "RED") {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            event.send("```Yes, that's it... you have the right idea. You're bleeding.```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Now, I want you to wait. Do not move. Do not say a word.```");
            std::this_thread::sleep_for(std::chrono::seconds(20));
            event.send("```Who's that in the distance, calling out to us?\nShouting bloody murder?\nCan you make them say it louder?```");
        }
        if (event.msg.content.substr(prefix.length()) == "blood" || event.msg.content.substr(prefix.length()) == "Blood"|| event.msg.content.substr(prefix.length()) == "BLOOD") {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            event.send("```Ding ding ding...```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Now, I want you to wait. Do not move. Do not say a word.```");
            std::this_thread::sleep_for(std::chrono::seconds(20));
            event.send("```Who's that in the distance, calling out to us?\nShouting bloody murder?\nCan you make them say it louder?```");
        }
    }
}