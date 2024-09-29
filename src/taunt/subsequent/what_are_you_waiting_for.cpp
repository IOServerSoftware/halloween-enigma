#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void what_are_you_waiting_for(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```People, what are you waiting for?\nYour damsel in distress, your princess in another castle is waiting.\nAnd I am growing more impatient for every day you delay.```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```And you know I do not kid around.```");
}