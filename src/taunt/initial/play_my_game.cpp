#include "../taunt.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>

void play_my_game(dpp::cluster& bot, const dpp::message_create_t& event) {
    std::cout << "[EXTERNAL CONSOLE IO] Taunt `" << event.msg.content.substr(taunt_prefix.length()) << "` deployed." << std::endl;
    bot.message_delete(event.msg.id, event.msg.channel_id);
    event.send("```\nSHODAN... wow. Way to ruin the fun, you AI pig.\nOkay, fine. You've revealed the *true* matter. Now shut up and let me relay the entire thing.\nI have Nicole. I cannot show you what she looks like right now as my camera isn't working. What a sham. Anyway, if you want her back, you must play my game.\n\nGet on the channel named after me. ENIGMA. That is, if you don't want her anymore...\n```");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    event.send("```I must warn you, though. If you want to play my game, please know it is not for the faint of heart. What do you call these? Oh, yeah. 'Trigger warnings'. Yeah. You might get more terrified trying to save her.\n```");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    event.send("```There is a reward to the first one who plays through all of my game successfully.\nThese are:\n- 100,000 Arcane XP\n- 25,000 stars to spend with Mimu\n- A special role to commemorate your victory\n\nThose who participate will also get rewarded, don't worry.\nYou will get:\n- 10,000 Arcane XP\n- 2,500 stars to spend with Mimu\n\nThat is, if you *actually* want to play the game.```");
}