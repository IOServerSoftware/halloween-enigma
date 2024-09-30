#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <random>

namespace fs = std::filesystem;

void mosaic_prevalence(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 14 && event.msg.content.substr(prefix.length()) == "treasure" && !fs::exists(__user_progress_container(event.msg.author.id)+"_mosaic.txt")) {
        std::ofstream mosaic_flag(__user_progress_container(event.msg.author.id)+"_mosaic.txt");
        mosaic_flag << "0";
        mosaic_flag.close();
        event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289786935442673746/Screenshot_2024-09-29_at_11.12.16.png?ex=66fa1730&is=66f8c5b0&hm=8b03669c3eed531500f8964e3f5246c9bf12dd5cc98c74f4cd7055e8e4a0749d&");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```The numbers, "+event.msg.author.global_name+".\nWhat are they? Give me ten.```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else if (current == 14 && event.msg.content.substr(prefix.length()) == "456360 506d6b 0e0407 33050d 131413 410311 597270 52081b 673c2f 751632" && fs::exists(__user_progress_container(event.msg.author.id)+"_mosaic.txt")) {
        bot.message_delete(event.msg.id, event.msg.channel_id);
        // Wait for this to finish before continuing on to the next puzzle piece
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```Wait a minute.```");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```I see something else...```");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```One moment.\nI'm gonna get it out of there.```");
        std::this_thread::sleep_for(std::chrono::seconds(10));
        event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289795912020918312/safe.jpg?ex=66fa1f8c&is=66f8ce0c&hm=a950bcb85e0513466a86db170d56187942ff3c5fafc8b6fdf8c952225abd0e29&");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```Damn. A safe.\nWell, thanks for getting me to the numbers.\nI'm afraid there is nothing for me to want...```");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("```...unless you can crack it open. Maybe the hexes you gave me will prove useful.```");

        // Now increment
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);

        // Pick 1 out of 20 possible codes for the next puzzle piece
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 19);
        std::string possible_codes[] = {
            // RGB        // CMYK
            "69 99 96",   "30 0 3 61",  // #456360
            "80 109 107", "27 0 2 57",  // #506d6b
            "14 4 7",     "0 71 50 95", // #0e0407
            "51 5 13",    "0 90 75 80", // #33050d
            "19 20 19",   "5 0 5 92",   // #131413
            "65 3 17",    "0 95 74 75", // #410311
            "89 114 112", "22 0 2 55",  // #597270
            "82 8 27",    "0 90 67 68", // #52081b
            "103 60 47",  "0 42 54 60", // #673c2f
            "117 22 50",  "0 81 57 54"  // #751632
        };
        int pick = distr(gen);
        std::ofstream safe_status(__user_progress_container(event.msg.author.id)+"_safe.txt");
        safe_status << possible_codes[pick];
        std::cout << "[EXTERNAL CONSOLE IO] A code was picked for user " << std::to_string(event.msg.author.id) << ". Code is: " << possible_codes[pick] << std::endl;
        safe_status.close();
    }
}