#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void shodan_hack_2(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```\nHELLO? SHODAN SPEAKING.\nI HOPE YOU HAVE TAKEN MY PREVIOUS PLEA INTO ACCOUNT WHILE YOU TRY TO SAVE MY HOST.\nI CANNOT LOSE NICOLE. I AM VERY CERTAIN YOU DO NOT WANT TO LOSE HER TOO.```");
}