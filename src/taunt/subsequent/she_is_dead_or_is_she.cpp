#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <chrono>
#include <thread>

void she_is_dead_or_is_she(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289758812290416702/SPOILER_is_she_dead.jpg?ex=66f9fcff&is=66f8ab7f&hm=ff9bbf517c305a00b188ff840f6b4b9a998fe7d0106f9e4f374d9c72745acb57&");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```Could this be...?\nHer suffering?\n\nMaybe. Maybe not.```");
}