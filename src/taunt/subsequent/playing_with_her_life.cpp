#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void playing_with_her_life(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```\nPeople...\nWhat good are your efforts when you don't try harder?\nNicole's life is on my hands. Don't delay. I'm playing with her life, so to speak.\nAnd I'm sure you want to play my game so I'd stop, right?```");
}