#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void she_is_here(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    if (current == 6 && event.msg.content.substr(prefix.length()) == "you") {
        std::ifstream check_progress(user_progress_path);
        increment_progress(user_progress_path, check_progress);
        event.send("```Who am I kidding? Of *course* it's me, you fool!\nWell... Nicole has this to say. I relay this to you in her writing.\n\n[BEGIN RELAY]\nguys... why is there a hole on the ground with my name on it? what is happening?! SOMEBODY GET OUT OF HERE PLEASE I CAN'T DO THIS ANYMORE SOBS\n[END RELAY]\n\nGuess the fate I planned for her. You'll have a clue with the audio I send...```\nhttps://cdn.discordapp.com/attachments/1288880397794672781/1288890094836645919/fate.mp3?ex=66f6d3f1&is=66f58271&hm=00cc9aff55f2a3def7bc0e551855276752298ede0b7dc0bbae7cbf4da8ee717c&");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
    } else return;
}