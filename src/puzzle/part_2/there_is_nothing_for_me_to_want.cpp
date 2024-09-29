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

void there_is_nothing_for_me_to_want(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::string safe_path = __user_progress_container(event.msg.author.id)+"_safe.txt";
    std::ifstream safe_storage(safe_path);
    std::string safe_code;
    std::getline(safe_storage, safe_code);
    safe_storage.close();

    if (current == 15) {
        if (event.msg.content.substr(prefix.length()) != safe_code) {
            return; // Do nothing
        }
        if (event.msg.content.substr(prefix.length()) == safe_code) {
            std::ifstream check_progress(user_progress_path);
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```What's this?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289915580102611005/pic.jpg?ex=66fa8eff&is=66f93d7f&hm=a8780631197f44890a9aa8547b6811565d53c5079315600e50a03e1ebde8c068&");
            std::this_thread::sleep_for(std::chrono::seconds(3));
            event.send("```My first victims... ah.```");
            std::this_thread::sleep_for(std::chrono::seconds(3));
            event.send("```Something's dripping... it's coming from you.\nIt's so vibrant that the snow is blemished with your mistakes.\n\nWhat could that be?\nCould it be coming from your NOSE?```");
        }
    }
}