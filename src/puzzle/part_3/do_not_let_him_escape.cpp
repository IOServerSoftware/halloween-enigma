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

bool is_running_after_enigma(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "chase") return true;
    if (event.msg.content.substr(prefix.length()) == "Chase") return true;
    if (event.msg.content.substr(prefix.length()) == "CHASE") return true;
    if (event.msg.content.substr(prefix.length()) == "run") return true;
    if (event.msg.content.substr(prefix.length()) == "Run") return true;
    if (event.msg.content.substr(prefix.length()) == "RUN") return true;
    return false;
}

bool is_enigma_caught(const dpp::message_create_t& event) {
    if (event.msg.content.substr(prefix.length()) == "catch") return true;
    if (event.msg.content.substr(prefix.length()) == "Catch") return true;
    if (event.msg.content.substr(prefix.length()) == "CATCH") return true;
    if (event.msg.content.substr(prefix.length()) == "tackle") return true;
    if (event.msg.content.substr(prefix.length()) == "Tackle") return true;
    if (event.msg.content.substr(prefix.length()) == "TACKLE") return true;
    if (event.msg.content.substr(prefix.length()) == "wrestle") return true;
    if (event.msg.content.substr(prefix.length()) == "Wrestle") return true;
    if (event.msg.content.substr(prefix.length()) == "WRESTLE") return true;
    return false;
}

void do_not_let_him_escape(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::ifstream check_progress(user_progress_path);
    bool is_close_to_enigma = false;
    if (current == 26) {
        if (!fs::exists(__user_progress_container(event.msg.author.id)+"_catch.txt")) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("I am not wasting any more time with you.");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("I am out of here!\nYou are not catching me alive!");
            std::ofstream catch_requirement(__user_progress_container(event.msg.author.id)+"_catch.txt");
            catch_requirement << "10";
            catch_requirement.close();
            std::ofstream catch_current(__user_progress_container(event.msg.author.id)+"_catchcount.txt");
            catch_current << "0";
            catch_current.close();
        } else if (is_running_after_enigma(event) && fs::exists(__user_progress_container(event.msg.author.id)+"_catch.txt")) {
            std::ifstream catch_progress(__user_progress_container(event.msg.author.id)+"_catchcount.txt");
            std::string catches;
            std::getline(catch_progress, catches);
            catch_progress.close();
            int new_chase = std::stoi(catches) + 1;
            std::ofstream write_chase(__user_progress_container(event.msg.author.id)+"_catchcount.txt", std::ofstream::trunc);
            write_chase << new_chase;
            write_chase.close();
            switch(new_chase) {
                case 1: event.send("Hah. You're not catching me."); break;
                case 2: event.send("Still not catching me..."); break;
                case 3: event.send("Stop trying.\nQuit struggling.\nYou're never gonna get me."); break;
                case 4: event.send("You're really not gonna stop, are you?"); break;
                case 5: event.send("Oh fuck."); break;
                case 6: event.send("*Oh, shit...*"); break;
                case 7: event.send("No!"); break;
                case 8: event.send("Stop that!"); break;
                case 9: event.send("Get away from me!"); break;
                case 10:
                    std::ofstream tackle(__user_progress_container(event.msg.author.id)+"_tackle.txt");
                    event.send("# OH NO!");
                    break;
            }
        } else if (is_enigma_caught(event) && fs::exists(__user_progress_container(event.msg.author.id)+"_tackle.txt")) {
            std::cout << "[EXTERNAL CONSOLE IO] Enigma is caught!" << std::endl;
            increment_progress(user_progress_path, check_progress);
            event.send("Agh, fuck!");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("Let go!");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send(".\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n# THIS ENDS NOW!");
            std::this_thread::sleep_for(std::chrono::seconds(5));
            event.send("# Nicole DIES here, and you *won't* see it happen.");
        }

    } 
}