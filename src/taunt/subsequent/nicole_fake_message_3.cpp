#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void nicole_fake_message_3(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    bot.execute_webhook_sync(fake_nicole, dpp::message("SOBS\nare you guys rlly not stopping? i appreciate what you're trying to do to 'save' me but i think this is too much LOL"));
}