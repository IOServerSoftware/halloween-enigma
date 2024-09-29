#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void give_her_up(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```People, people, people.\nWhen will you ever learn to give up?```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    bot.execute_webhook_sync(fake_nicole, dpp::message("ikr. smhhhhhh"));
}