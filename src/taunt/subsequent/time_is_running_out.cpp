#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void time_is_running_out(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```\nHickory, dickory, dock.\nNicole ran up the clock.\nThe clock struck three, and down she flees...\nHickory, dickory, dock.\nTick.\nTock.\nTick.\nTock.\nAre you doing anything to save your Nicole?```");
}