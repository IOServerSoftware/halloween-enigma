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

// Caesar
void final_confrontation_pt_1(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 29 && is_player_ready(event) && !fs::exists(__user_progress_container(event.msg.author.id)+"_caesar.txt")) {
        std::ofstream caesar_flag(__user_progress_container(event.msg.author.id)+"_caesar.txt");
        caesar_flag.close();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("Don't say I didn't warn you.");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("```"+caesar.cipher_text+"```");
    } else if (current == 29 && fs::exists(__user_progress_container(event.msg.author.id)+"_caesar.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_caesar-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == caesar.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << caesar.cipher_type << " cipher was solved!" << std::endl;
            std::ofstream caesar_complete(__user_progress_container(event.msg.author.id)+"_caesar-dec.txt");
            caesar_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("Nice, but not shocking.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Shall we go to the next?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Tell me when you're ready as always.");
        }
    } else if (current == 29 && fs::exists(__user_progress_container(event.msg.author.id)+"_caesar-dec.txt") && is_player_ready(event)) {
        increment_progress(user_progress_path, check_progress);
        event.send("Hm, alright. This should be second nature for you.");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::ofstream rot13_flag(__user_progress_container(event.msg.author.id)+"_rot13.txt");
        rot13_flag.close();
        event.send("```"+rot13.cipher_text+"```");
    }
}