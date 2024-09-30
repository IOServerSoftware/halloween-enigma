#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

enum Lie { SOLVED, UNSOLVED, NOT_TRYING };
Lie is_solved(std::string attempt) {
    if (attempt == "FOR DEATH IS BUT A PASSAGE TO A NEW WORLD.") return SOLVED;
    if (attempt == "For death is but a passage to a new world.") return SOLVED;
    if (attempt == "for death is but a passage to a new world.") return SOLVED;
    if (attempt == "HCE IYSBV VU PHY U HIGFCUR YI S VSJ YCEQX.") return UNSOLVED;
    if (attempt == "hce iysbv vu phy u higfcur yi s vsj yceqx.") return UNSOLVED;
    return NOT_TRYING;
}

void lies(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 11 && event.msg.content.substr(prefix.length()) == "01370705" && !fs::exists("db/"+std::to_string(event.msg.author.id)+"_lies.txt")) {
        if (!fs::exists(__user_progress_container(event.msg.author.id)+"_lies.txt")) {
            std::ofstream write_lies(__user_progress_container(event.msg.author.id)+"_lies.txt");
            write_lies << "1";
            write_lies.close();
        }
        event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289024002009862195/code_1.wav?ex=66f750a6&is=66f5ff26&hm=c641a73de9ce62c9b0d93c77c6d827d281d2212a1c4881458efbe5da1d795e76&");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else if (current == 11 && fs::exists(__user_progress_container(event.msg.author.id)+"_lies.txt")) {
        Lie lie = is_solved(event.msg.content.substr(prefix.length()));
        std::ifstream check_progress(user_progress_path);
        bot.message_delete(event.msg.id, event.msg.channel_id);
        switch (lie) {
            case SOLVED:
                increment_progress(user_progress_path, check_progress);
                event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289024002400059453/code_2.wav?ex=66f750a7&is=66f5ff27&hm=dc9accb9ee54de85ce44d5098d7ce84054c7b85a174b536272a3875ffdb1814c&");
                std::this_thread::sleep_for(std::chrono::seconds(60));
                event.send("```Now who do you see when you're being spied on?```");
                break;
            case UNSOLVED:
                event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289024001691353098/code_1_1.wav?ex=66f750a6&is=66f5ff26&hm=664f6a984b46c14b72925f6a3cae5934ad02e8c4c34ea4e607dbf1552f79d0f1&");
                break;
            default: break;
        }
        check_progress.close();
    }
}