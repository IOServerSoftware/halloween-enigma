#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void shodan_hack_3(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```\nSHODAN AGAIN.\nI CAN ALREADY SENSE SOMETHING BAD IS ABOUT TO HAPPEN TO HER...\nTREAD LIGHTLY, BE CAREFUL. SAVE HER.\nI CANNOT BEG ENOUGH.```");
}