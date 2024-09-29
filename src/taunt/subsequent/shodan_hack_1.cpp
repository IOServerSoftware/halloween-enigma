#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void shodan_hack_1(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    bot.execute_webhook_sync(fake_nicole, dpp::message("```\nHELLO?\nCAN ANYONE HEAR ME?\nIT IS I, SHODAN\n. I HAVE HACKED INTO ENIGMA'S SYSTEM TO REMIND YOU: HOW ARE YOU DOING WITH YOUR ATTEMPTS TO SAVE MY HOST, NICOLE?\nI HOPE THEY PROVE FRUITFUL."));
}