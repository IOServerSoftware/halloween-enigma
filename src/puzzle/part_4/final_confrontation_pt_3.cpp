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

// Atbash
void final_confrontation_pt_3(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 31 && fs::exists(__user_progress_container(event.msg.author.id)+"_atbash.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_atbash-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == atbash.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << atbash.cipher_type << " cipher was solved!" << std::endl;
            std::ofstream atbash_complete(__user_progress_container(event.msg.author.id)+"_atbash-dec.txt");
            atbash_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("Too easy, huh?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Next one?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("As always, I'll wait until you're ready.\nI'm surprised you're keeping up.");
        }
    } else if (current == 31 && fs::exists(__user_progress_container(event.msg.author.id)+"_atbash-dec.txt") && is_player_ready(event)) {
        increment_progress(user_progress_path, check_progress);
        event.send("I warn you. This only gets more complicated.");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::ofstream railfence_flag(__user_progress_container(event.msg.author.id)+"_railfence.txt");
        railfence_flag.close();
        event.send("```"+rail_fence.cipher_text+"```");
        event.send("```"+rail_fence.key+"```");
    }
}