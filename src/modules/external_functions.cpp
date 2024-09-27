#include "external_functions.h"
#include "../puzzle/puzzle.h"
#include "../taunt/taunt.h"
#include "../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

int read_progress(std::string& user_progress_path) {
    std::ifstream current_progress(user_progress_path);
    std::string puzzle_progress;
    std::getline(current_progress, puzzle_progress);
    current_progress.close();
    std::cout << "[EXTERNAL CONSOLE IO] Grabbed `" << puzzle_progress << "` from " << user_progress_path << std::endl;
    return std::stoi(puzzle_progress);
}

void increment_progress(std::string& user_progress_path, std::ifstream& current_progress) {
    std::string puzzle_progress;
    std::getline(current_progress, puzzle_progress);
    current_progress.close();
    int count = std::stoi(puzzle_progress) + 1;
    std::ofstream new_progress(user_progress_path, std::ofstream::trunc);
    new_progress << count;
    std::cout << "[EXTERNAL CONSOLE IO] Progress incremented on " << user_progress_path << " to " << count << "." << std::endl;
    new_progress.close();
}

// Separate function for handling prefix-based commands
void handle_puzzle_prompts(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd, std::istringstream& args) {
    std::string user_progress_path = __user_progress_container(event.msg.author.id) + std::to_string(event.msg.author.id) + ".txt";
    if (!fs::exists(user_progress_path)) {
        std::cout << "[EXTERNAL CONSOLE IO] The game has started for " << event.msg.author.id << "." << std::endl;
        if (fs::create_directory(__user_progress_container(event.msg.author.id))) {
            std::cout << "[EXTERNAL CONSOLE IO] Directory " << __user_progress_container(event.msg.author.id) << " created." << std::endl;
        } else {
            std::cout << "[EXTERNAL CONSOLE IO] Failed to create directory " << __user_progress_container(event.msg.author.id) << " because an error occurred." << std::endl;
        }
        std::ofstream progress_file(user_progress_path);
        std::cout << "[EXTERNAL CONSOLE IO] File written on " << user_progress_path << std::endl;
        progress_file << "1";
        progress_file.close();
    }
    PuzzleStatus puzzle_status;
    if (event.msg.is_dm()) {
        puzzle_status = NOT_STARTED;
        std::cout << "[EXTERNAL CONSOLE IO] DM detected. Ignoring..." << std::endl;
        event.send("```You weren't supposed to talk to me here, were you?```");
        return;
    } else {
        puzzle_status = get_status(read_progress(user_progress_path));
    }
    switch (puzzle_status) {
        // part 1
        case START: puzzle_init(bot, event, user_progress_path); break;
        case BLACKBIRD: blackbird(bot, event, user_progress_path); break;
        case DEAD_EYE: dead_eye(bot, event, user_progress_path); break;
        case NOTHING_IS_WHAT_IT_SEEMS: nothing_is_what_it_seems(bot, event, user_progress_path); break;
        case HALLUCINATIONS: hallucinations(bot, event, user_progress_path); break;
        case SHE_IS_HERE: she_is_here(bot, event, user_progress_path); break;
        case GRAVESTONE: gravestone(bot, event, user_progress_path); break;
        case SUSPICION: suspicion(bot, event, user_progress_path); break;
        case FORGOTTEN: forgotten(bot, event, user_progress_path); break;
        case LOGON: logon(bot, event, user_progress_path); break;

        // part 2
        case LIES: lies(bot, event, user_progress_path); break;

        /*
        case STALKER: stalker(bot, event, user_progress_path); break;
        case SIX_FEET: six_feet(bot, event, user_progress_path); break;
        case IN_THE_WOODS: in_the_woods(bot, event, user_progress_path); break;
        case THERE_IS_NOTHING_FOR_ME_TO_WANT: there_is_nothing_for_me_to_want(bot, event, user_progress_path); break;
        case RED_SNOW: red_snow(bot, event, user_progress_path); break;
        case SOMEONE_IS_WAITING: someone_is_waiting(bot, event, user_progress_path); break;
        case NO_SENSE_OF_SELF: no_sense_of_self(bot, event, user_progress_path); break;
        case YOU_DO_NOT_MAKE_SENSE: you_do_not_make_sense(bot, event, user_progress_path); break;
        case I_FOUND_HER_QUESTION_MARK: i_found_her_question_mark(bot, event, user_progress_path); break;

        // part 3
        case WHO_IS_SHE: who_is_she(bot, event, user_progress_path); break;
        case WHAT_ARE_YOU: what_are_you(bot, event, user_progress_path); break;
        case WHERE_IS_SHE: where_is_she(bot, event, user_progress_path); break;
        case WHY_WOULD_YOU_DO_THIS: why_would_you_do_this(bot, event, user_progress_path); break;
        case YOU_HAVE_GOT_TO_STOP: you_have_got_to_stop(bot, event, user_progress_path); break;
        case DO_NOT_LET_HIM_ESCAPE: do_not_let_him_escape(bot, event, user_progress_path); break;
        case NICOLE_DIES: nicole_dies(bot, event, user_progress_path); break;
        case ONE_LAST_PUZZLE: one_last_puzzle(bot, event, user_progress_path); break;

        // Final confrontation
        case FINAL_CONFRONTATION_PT_1: final_confrontation_pt_1(bot, event, user_progress_path); break;
        case FINAL_CONFRONTATION_PT_2: final_confrontation_pt_2(bot, event, user_progress_path); break;
        case FINAL_CONFRONTATION_PT_3: final_confrontation_pt_3(bot, event, user_progress_path); break;
        case FINAL_CONFRONTATION_PT_4: final_confrontation_pt_4(bot, event, user_progress_path); break;
        case FINAL_CONFRONTATION_PT_5: final_confrontation_pt_5(bot, event, user_progress_path); break;
        case FINAL_CONFRONTATION_PT_6: final_confrontation_pt_6(bot, event, user_progress_path); break;

        // Ending pieces
        case NICOLE_IS_SAVED: nicole_is_saved(bot, event, user_progress_path); break;
        case THIS_IS_NOT_THE_LAST_OF_ME: this_is_not_the_last_of_me(bot, event, user_progress_path); break;
        case THERE_IS_ANOTHER: there_is_another(bot, event, user_progress_path); break;
        */

        default:
            // Logon patch
            if (fs::exists("db/"+std::to_string(event.msg.author.id)+"_logged-on.txt") && read_progress(user_progress_path) == 10) {
                logon(bot, event, user_progress_path);
                std::cout << "[EXTERNAL CONSOLE IO] Log-on status detected" << std::endl;
            }
        break; // Handle any unexpected cases
    }
}

void handle_taunt_prompts(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd) {
    if (event.msg.is_dm()) {
        std::cout << "[EXTERNAL CONSOLE IO] DM detected. Ignoring..." << std::endl;
        event.send("```I mean, I can taunt you in here. But why would I?```");
        return;
    } else if (event.msg.author.id == owner_id) {
        Taunt taunt = get_taunt(cmd);
        switch (taunt) {
            // initial
            case NICOLE_IS_KIDNAPPED: nicole_is_kidnapped(bot, event); break;
            case PLAY_MY_GAME: play_my_game(bot, event); break;

            // subsequent
            case PLAYING_WITH_HER_LIFE: playing_with_her_life(bot, event); break;
            case NICOLE_FAKE_MESSAGE_1: nicole_fake_message_1(bot, event); break;
            case NICOLE_FAKE_MESSAGE_2: nicole_fake_message_2(bot, event); break;
            case NICOLE_FAKE_MESSAGE_3: nicole_fake_message_3(bot, event); break;
        }
    } else if (event.msg.author.id != owner_id) {
        bot.message_delete(event.msg.id, event.msg.channel_id);
    }
}