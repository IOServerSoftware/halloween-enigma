#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void play_my_game(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```SHODAN... wow. Way to ruin the fun, you AI pig.\nOkay, fine. You've revealed the *true* matter. Now shut up and let me relay the entire thing.\nI have Nicole. I cannot show you what she looks like right now as my camera isn't working. What a sham. Anyway, if you want her back, you must play my game.\n\nGet on the channel named after me. ENIGMA. That is, if you don't want her anymore...```");
}