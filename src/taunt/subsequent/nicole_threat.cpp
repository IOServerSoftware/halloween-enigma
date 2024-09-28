#include "../taunt.h"
#include "../../cfg/config.h"
#include <thread>
#include <chrono>
#include <dpp/dpp.h>
#include <iostream>

void nicole_threat(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```You are making me grow impatient.\nNicole suffers thanks to you.\nYou keep this going, what remains of her will be on your hands.```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    event.send("https://cdn.discordapp.com/attachments/1288880397794672781/1289222425644630047/nicole_threat.mp3?ex=66f80972&is=66f6b7f2&hm=9b57ac9b147ab1ddb393458b97c55fb36bacb6c381beb8684bb93313c99fa457&");
}