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

// Rail fence
void final_confrontation_pt_4(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 32 && fs::exists(__user_progress_container(event.msg.author.id)+"_railfence.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_railfence-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == rail_fence.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << rail_fence.cipher_type << " cipher was solved!" << std::endl;
            std::ofstream atbash_complete(__user_progress_container(event.msg.author.id)+"_railfence-dec.txt");
            atbash_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("How?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("How did you get that?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Just how...?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("This is shocking.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("But I'm not one to deny talent, am I?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Next one when you're ready.");
        }
    } else if (current == 32 && fs::exists(__user_progress_container(event.msg.author.id)+"_railfence-dec.txt") && is_player_ready(event)) {
        increment_progress(user_progress_path, check_progress);
        event.send("Before I introduce you to the most complicated piece, let me show you...\n# THIS!");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::ofstream vigenere_flag(__user_progress_container(event.msg.author.id)+"_vigenere.txt");
        vigenere_flag.close();
        event.send("```"+vigenere.cipher_text+"```");
        event.send("```"+vigenere.key+"```");
    }
}