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

bool ask_if_no_sense(const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Does it make sense? (" << event.msg.content.substr(prefix.length()) << ")" << std::endl;
    if (event.msg.content.substr(prefix.length()) == "you don't") return true;
    if (event.msg.content.substr(prefix.length()) == "You don't") return true;
    if (event.msg.content.substr(prefix.length()) == "YOU DON'T") return true;
    if (event.msg.content.substr(prefix.length()) == "you don’t") return true;
    if (event.msg.content.substr(prefix.length()) == "You don’t") return true;
    if (event.msg.content.substr(prefix.length()) == "YOU DON’T") return true;
    if (event.msg.content.substr(prefix.length()) == "you dont") return true;
    if (event.msg.content.substr(prefix.length()) == "You dont") return true;
    if (event.msg.content.substr(prefix.length()) == "YOU DONT") return true;
    if (event.msg.content.substr(prefix.length()) == "you do not") return true;
    if (event.msg.content.substr(prefix.length()) == "You do not") return true;
    if (event.msg.content.substr(prefix.length()) == "YOU DO NOT") return true;
    else return false;
}

void you_do_not_make_sense(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 19) {
        std::cout << "[EXTERNAL CONSOLE IO] That can't be Nicole... (User is now in puzzle piece id 19)" << std::endl;
        if (ask_if_no_sense(event)) {
            increment_progress(user_progress_path, check_progress);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```What the fuck.```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```You're shit-talking me?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```You're standing up to me?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Hah. Can't say I'm surprised.\nThat reaction was a joke.```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```But I think I've helped you here. Right?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Look ahead.```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289924981916045372/maybe_nicole.png?ex=66fa97c1&is=66f94641&hm=a7bb6f06f9c6b9e010e41cebeba341bb20bcf444b89718597a725ad6cdb27eab&");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Now, who could this be?```");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("```Ask yourself. Who do you *think* could she be?```");
        }
    }
}