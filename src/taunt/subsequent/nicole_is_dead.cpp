#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void nicole_is_dead(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("Haha.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("HAHA.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("# HAHAHAHAHAHAHAHA!");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289980489523789935/dead.jpeg?ex=66facb73&is=66f979f3&hm=76cdeb4ed8af8fc8ab72374fd19ff2df0990da7af2b0ff9e7cfb3b391b28b04f&");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("Her soul is mine now.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("You have taken too long!");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("Some of you have tried so hard to save this woman...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("...but in the end, it doesn't even matter.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("# She.");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    event.send("# Is.");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    event.send("# Dead.");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    event.send("Nada. Nichts. Keine. No more.");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("```GAME OVER.\nThe event is over.```");
}