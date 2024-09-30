#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void death_threat(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("# YOUR TIME IS RUNNING OUT!");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```I have her boyfriend... guess what?```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("||https://cdn.discordapp.com/attachments/1288880397794672781/1290003634955747399/bf_dead.png?ex=66fae101&is=66f98f81&hm=03797ff8de236f42b2bee858ed3eac4230540f10a330c593fd3c68c94b2ba313&||");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    event.send("```BAM!```");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    event.send("```He is no more.```");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    event.send("```And if you keep this up, *she* will be next.```");
}