#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void nicole_fake_message_1(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    bot.execute_webhook_sync(fake_nicole, dpp::message("hey guysss!\ni'm doing okay, this person is just taking care of me so well. why are you so worried??? dw i'm okayyyyy nothing bad is happening. please stop worrying thankies byee!"));
}