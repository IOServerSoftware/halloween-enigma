#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void puzzle_init(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 1 && event.msg.content.substr(prefix.length()) == "start" && !fs::exists(__user_progress_container(event.msg.author.id)+"_started.txt")) {
        // User has started puzzle
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```And so you finally come.\n\nI have your golden girl with me... what was her name? Ah, right. NICOLE. Bad, bad things befell(1,5) her.\nShe never thought to call(2,1) for people to stand, sulking(4) rather aimlessly on borrowed(1) time(2).\nShe knows the punishments.\nYou can already(3) think about what I'm going to do(1) to her when I sent that recording...\n\nGood luck with my mind game.\n\nPlease remember that my game has multiple trigger warnings.\nIf you respond with the correct answer to this prompt, I assume that you have understood these trigger warnings, and I will not be held responsible for any reactions you may have over my game.```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        std::ofstream start_flag(__user_progress_container(event.msg.author.id)+"_started.txt");
        start_flag.close();
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}