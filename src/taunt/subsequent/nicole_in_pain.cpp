#include "../taunt.h"
#include "../../cfg/config.h"
#include <thread>
#include <chrono>
#include <dpp/dpp.h>
#include <iostream>

void nicole_in_pain(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289227439402385592/nicole.mp3?ex=66f80e1e&is=66f6bc9e&hm=ec923b273f85c24c7433539c72ed315b967fe4c49dbf98cf76e51ac5b8f96de2&");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```Hear what I am doing to her because of your inaction.\nYou're going to hear her screams when you sleep at night...```");
}