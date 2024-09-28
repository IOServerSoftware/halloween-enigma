#include "../taunt.h"
#include "../../cfg/config.h"
#include <thread>
#include <chrono>
#include <dpp/dpp.h>
#include <iostream>

void nicole_pleading(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289230800780263424/when_will_you_save_her.mp3?ex=66f8113f&is=66f6bfbf&hm=b07cd979df8957f9238e7d7d2ed87fd3bcbb62c9fdb3a46873d0c2f232503034&");
}