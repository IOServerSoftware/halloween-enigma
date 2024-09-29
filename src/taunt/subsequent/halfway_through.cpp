#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void halfway_through(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```We have a long ways to go, and it's already halfway through. What is going on with you all? Sloths...```");
}