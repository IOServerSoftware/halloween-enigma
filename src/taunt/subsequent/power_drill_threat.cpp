#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void power_drill_threat(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```Watch it...```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289787513422086227/toy.mp3?ex=66fa17ba&is=66f8c63a&hm=5142d3411693645687f3eeefc5361df09b46afd8725d15e01eaefd6337113ced&");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```I have this thing floating over her best friend's head...```");
}