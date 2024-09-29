#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void power_drill_on_bestie(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289914201774493706/lucy.mp3?ex=66fa8db7&is=66f93c37&hm=e76d7f7638957596e4d42d688433527a9092ec98d70b37f7aa70ec394f7e2176&");
    std::this_thread::sleep_for(std::chrono::seconds(90));
    event.send("```She's dead now...\nThis is what happens when you keep trying.\nNicole mourns because of you.\n\nAre you happy?```");
}