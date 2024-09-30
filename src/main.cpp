#include <iostream>
#include <dpp/dpp.h>
#include <string>
#include "cfg/config.h"
#include "modules/external_functions.h"

int main() {
    dpp::cluster bot(bot_token, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (event.shard_id == 0) {
            std::cout << "[EXTERNAL CONSOLE IO] Enigma is ready." << std::endl;
        }
    });

    // Handle prefix-based commands
    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        std::string content = event.msg.content;

        // Check if the message starts with the prefix
        if (content.rfind(prefix, 0) == 0) {
            std::string command = content.substr(prefix.length());
            std::istringstream iss(command);
            std::string cmd;
            iss >> cmd; // Extract command
            handle_puzzle_prompts(bot, event, cmd, iss);
        }
        
        if (content.rfind(taunt_prefix, 0) == 0) {
            std::string cmd = content.substr(taunt_prefix.length());
            handle_taunt_prompts(bot, event, cmd);
        }
    });

    bot.start(dpp::st_wait);
}
