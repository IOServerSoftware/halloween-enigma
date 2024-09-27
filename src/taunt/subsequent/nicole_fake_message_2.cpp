#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void nicole_fake_message_2(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    bot.execute_webhook_sync(fake_nicole, dpp::message("guys. guys. that fucking idiot is just a troll who wants nothing more than attention. please don't waste your time on me, i'm okayyyy! my heart is actually doing pretty good too so who knows."));
}