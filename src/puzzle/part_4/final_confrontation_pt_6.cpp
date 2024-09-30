#include "climax.h"
#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

bool is_apocalypse(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "apocalypse") return true;
    if (event.msg.content.substr(prefix.length()) == "Apocalypse") return true;
    if (event.msg.content.substr(prefix.length()) == "APOCALYPSE") return true;
    if (event.msg.content.substr(prefix.length()) == "end of the world") return true;
    if (event.msg.content.substr(prefix.length()) == "End of the world") return true;
    if (event.msg.content.substr(prefix.length()) == "End of the World") return true;
    if (event.msg.content.substr(prefix.length()) == "END OF THE WORLD") return true;
    if (event.msg.content.substr(prefix.length()) == "extinction") return true;
    if (event.msg.content.substr(prefix.length()) == "Extinction") return true;
    if (event.msg.content.substr(prefix.length()) == "EXTINCTION") return true;
    if (event.msg.content.substr(prefix.length()) == "armageddon") return true;
    if (event.msg.content.substr(prefix.length()) == "Armageddon") return true;
    if (event.msg.content.substr(prefix.length()) == "ARMAGEDDON") return true;
    return false;
}

// Vigenere
void final_confrontation_pt_6(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    if (current == 34 && fs::exists(__user_progress_container(event.msg.author.id)+"_enigma.txt") && !fs::exists(__user_progress_container(event.msg.author.id)+"_enigma-dec.txt")) {
        if (event.msg.content.substr(prefix.length()) == enigma.solved_text) {
            std::cout << "[EXTERNAL CONSOLE IO] " << enigma.cipher_type << " cipher was solved! Enigma is defeated. Almost." << std::endl;
            std::ofstream vigenere_complete(__user_progress_container(event.msg.author.id)+"_enigma-dec.txt");
            vigenere_complete.close();
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("No...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("**No!**");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# NOOOOOOOOOOOOOO!");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send(".\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n# ENOUGH!");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Now you cannot scroll up anymore!");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("I have one final question of you...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# What do all of my ramblings talk about?");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("There is one theme: very easy to get.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("If you don't get this...");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("# Nicole dies.");
        }
    } else if (current == 34 && fs::exists(__user_progress_container(event.msg.author.id)+"_enigma-dec.txt")) {
        if (is_apocalypse(event)) {
            // you win
            bot.message_delete(event.msg.id, event.msg.channel_id);
            std::cout << "[EXTERNAL CONSOLE IO] Nicole is saved for user id " << std::to_string(event.msg.author.id) << "!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Congratulations.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("You've bested me.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("You can have your golden girl back now.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("Just CLAIM her...");
            increment_progress(user_progress_path, check_progress);
        } else if (!is_apocalypse(event)) {
            // game over
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
            event.send("I can't ignore your efforts, though.");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            event.send("You tried so hard to save this woman...");
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
            event.send("```GAME OVER.\n\nYour progress was RESET back to the beginning!\nTry again by typing `> start`.```");
            reset_progress(__user_progress_container(event.msg.author.id), event);
        }
    }
}