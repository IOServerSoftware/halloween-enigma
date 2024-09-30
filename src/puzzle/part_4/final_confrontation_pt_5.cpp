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

// Vigenere
void final_confrontation_pt_5(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 33 && fs::exists(__user_progress_container(event.msg.author.id)+"_vigenere.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_vigenere-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == vigenere.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << vigenere.cipher_type << " cipher was solved!" << std::endl;
            std::ofstream vigenere_complete(__user_progress_container(event.msg.author.id)+"_vigenere-dec.txt");
            vigenere_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("You...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# WHAT?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("This is a twist. If you should continue, just tell me when you're ready.\n# BUT I WARN YOU: IT WON'T BE EASY.");
        }
    } else if (current == 33 && fs::exists(__user_progress_container(event.msg.author.id)+"_vigenere-dec.txt") && is_player_ready(event)) {
        increment_progress(user_progress_path, check_progress);
        event.send("# YOU WILL NEVER SOLVE THIS!");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("# The Germans have been using this method to mess up their messages in the war!");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        event.send("# Good FUCKING luck!");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::ofstream enigma_flag(__user_progress_container(event.msg.author.id)+"_enigma.txt");
        enigma_flag.close();
        event.send("```"+enigma.cipher_text+"```");
        event.send("```"+enigma.key+"```");
    }
}