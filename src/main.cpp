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
        std::cout << "[EXTERNAL CONSOLE IO] Message captured: `" << event.msg.content << "`" << std::endl;
        std::string content = event.msg.content;

        // Check if the message starts with the prefix
        if (content.rfind(prefix, 0) == 0) {
            std::string command = content.substr(prefix.length());
            std::istringstream iss(command);
            std::string cmd;
            iss >> cmd; // Extract command

            std::cout << "[EXTERNAL CONSOLE IO] Prefix detected. Handling puzzle output..." << std::endl;
            handle_puzzle_prompts(bot, event, cmd, iss);
        }
        
        if (content.rfind(taunt_prefix, 0) == 0) {
            std::string command = content.substr(taunt_prefix.length());
            std::istringstream iss(command);
            std::string cmd;
            iss >> cmd; // Extract command

            std::cout << "[EXTERNAL CONSOLE IO] Taunt trigger detected." << std::endl;
            handle_taunt_prompts(bot, event, cmd, iss);
        }
    });

    bot.start(dpp::st_wait);
}
