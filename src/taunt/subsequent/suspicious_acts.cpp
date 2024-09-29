#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void suspicious_acts(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```Guess what? I'm in Nicole's room in her house while she's stuck on mine.\nHmm...```");
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289423034112938014/something_is_happening.mp3?ex=66f8c447&is=66f772c7&hm=450f1d28a51326685a8ab372a60d267697fb893bf2beb5f5adc88f9318730c7e&");
}