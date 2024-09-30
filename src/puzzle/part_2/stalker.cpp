#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <thread>
#include <chrono>
#include "../puzzle.h"
#include "../../cfg/config.h"
#include "../../modules/external_functions.h"

namespace fs = std::filesystem;

void stalker(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 12 && event.msg.content.substr(prefix.length()) == "stalker" && !fs::exists(__user_progress_container(event.msg.author.id)+"_stalker.txt")) {
        std::cout << "[EXTERNAL CONSOLE IO] Stalker protocol engaged." << std::endl;
        std::ofstream stalker_flag(__user_progress_container(event.msg.author.id)+"_stalker.txt");
        stalker_flag.close();
        event.send("```Could there be somebody watching you?```");
        bot.message_delete(event.msg.id, event.msg.channel_id);
        std::this_thread::sleep_for(std::chrono::seconds(15));
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Nope, never mind.\nBut where do you find yourself, in the stones and names engraved on the floor and erected from the dead?\n\nTell me where you are.\nWhat do you do for your dead?```");
    }
}
