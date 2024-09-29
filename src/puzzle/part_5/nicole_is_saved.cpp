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

void nicole_is_saved(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 35) {
        if (event.msg.content.substr(prefix.length()) == "claim" || event.msg.content.substr(prefix.length()) == "Claim"|| event.msg.content.substr(prefix.length()) == "CLAIM") {
            bot.message_delete(event.msg.id, event.msg.channel_id);
            event.send("So this is it...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Game over for me.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("And a win to you.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("But this will not be our last moment together.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# YOU HEAR ME?!");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# THIS ISN'T OVER!");
            std::this_thread::sleep_for(std::chrono::seconds(10));
            increment_progress(user_progress_path, check_progress);
            if (!fs::exists("db/first.txt")) {
                std::ofstream first_saviour("db/first.txt");
                first_saviour << std::to_string(event.msg.author.id);
                event.send("```CONGRATULATIONS!\n\nYou are the **FIRST** to save Nicole!\nPlease send this result to staff members through a ticket to claim your rewards.\n\nThank you for participating!```");
            } else if (fs::exists("db/first.txt")) {
                event.send("```CONGRATULATIONS!\n\nYou've saved Nicole!\nPlease send this result to staff members through a ticket to claim your rewards.\n\nThank you for participating!```");
            }
            
        }
    }
}