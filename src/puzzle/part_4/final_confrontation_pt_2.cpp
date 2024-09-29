#include "climax.h"
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

// ROT13
void final_confrontation_pt_2(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 30 && fs::exists(__user_progress_container(event.msg.author.id)+"_rot13.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_rot13-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == rot13.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << rot13.cipher_type << " cipher was solved!" << std::endl;
            std::ofstream rot_complete(__user_progress_container(event.msg.author.id)+"_rot13-dec.txt");
            rot_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("Good.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Next one?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("I'll wait when you're ready.");
        }
    } else if (current == 30 && fs::exists(__user_progress_container(event.msg.author.id)+"_rot13-dec.txt") && is_player_ready(event)) {
        increment_progress(user_progress_path, check_progress);
        event.send("Okay... wow. You really want to save this girl, do you?");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::ofstream atbash_flag(__user_progress_container(event.msg.author.id)+"_atbash.txt");
        atbash_flag.close();
        event.send("```"+atbash.cipher_text+"```");
    }
}