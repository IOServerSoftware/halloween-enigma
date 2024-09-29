#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void more_pain(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289783608222941205/where_are_you.mp3?ex=66fa1417&is=66f8c297&hm=53e339487c10b309603e1f0783c2055fa8ae122e81c4fada7d0bacefee327233&");
}