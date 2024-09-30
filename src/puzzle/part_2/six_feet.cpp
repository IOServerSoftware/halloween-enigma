#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void six_feet(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    int dig_count = 0;
    std::string funeral_progress_path = __user_progress_container(event.msg.author.id)+"_funeral.txt";
    if (current == 13 && event.msg.content.substr(prefix.length()) == "funeral") {
        std::ofstream funeral_flag(__user_progress_container(event.msg.author.id)+"_funeral.txt");
        funeral_flag << "0";
        funeral_flag.close();
        event.send("```Welcome.\nThere seems to be something we want at the bottom of this grave.\nThere is no dead body.\nThere are no zombies either, I can tell you this much.\n\nCan you DIG for me?```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else if (current == 13 && event.msg.content.substr(prefix.length()) == "dig" && fs::exists(__user_progress_container(event.msg.author.id)+"_funeral.txt")) {
        std::ifstream funeral_progress(funeral_progress_path);
        std::string digs;
        std::getline(funeral_progress, digs);
        funeral_progress.close();
        int new_digs = std::stoi(digs) + 1;
        std::ofstream write_digs(funeral_progress_path, std::ofstream::trunc);
        write_digs << new_digs;
        write_digs.close();
        if (new_digs == 1) {
            event.send("```You are 1 foot under.```");
        } else if (new_digs > 1 && new_digs < 6) {
            event.send("```You are "+std::to_string(new_digs)+" feet under.```");
        } else if (new_digs == 6) {
            std::ifstream check_progress(user_progress_path);
            increment_progress(user_progress_path, check_progress);
            event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289782487345664062/funeral_box.jpg?ex=66fa130b&is=66f8c18b&hm=1ed258b896674ea910fdff509f07d05b7ad5a30db4e499da87bfbd8bfb5702fe&");
            event.send("```What could be inside...?```");
        }
    }
}