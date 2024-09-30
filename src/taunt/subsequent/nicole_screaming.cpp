#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void nicole_screaming(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    bot.execute_webhook_sync(fake_nicole, dpp::message("https://cdn.discordapp.com/attachments/1288880397794672781/1289998385092235355/she_screams.mp3?ex=66fadc1e&is=66f98a9e&hm=df755da5728e10b4299ad4530866a7e518db70ae6e8cbe5c8abbeb676b4be2dc&"));
}