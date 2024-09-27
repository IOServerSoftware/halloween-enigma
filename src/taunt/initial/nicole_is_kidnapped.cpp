#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void nicole_is_kidnapped(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```HELLO THERE...\nHere is the matter of the situation regarding this fabricated AMBER alert you may have seen.\nIt was merely a false alarm, nothing happened to this... Nicole.\nI promise you.\nNothing has happened to her.```");
}