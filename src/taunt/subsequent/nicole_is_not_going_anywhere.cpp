#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <thread>
#include <chrono>

void nicole_is_not_going_anywhere(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```Oh, my dear Nicole... you wouldn't run from me, will you?\nYou wouldn't go anywhere, and instead stay with me, right?```");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    bot.execute_webhook_sync(fake_nicole, dpp::message("yup! you know i wouldnttttt ever. :))"));
}