#pragma once
#ifndef puzzle_h
#define puzzle_h

#include <dpp/dpp.h>
#define __user_progress_container(x) "db/"+ std::to_string(x) + "/"

// This structure is in order
enum PuzzleStatus {
    // part 1
    START, BLACKBIRD, DEAD_EYE, NOTHING_IS_WHAT_IT_SEEMS, HALLUCINATIONS, SHE_IS_HERE, GRAVESTONE, SUSPICION, FORGOTTEN, LOGON,
    // part 2
    LIES, STALKER, SIX_FEET, IN_THE_WOODS, THERE_IS_NOTHING_FOR_ME_TO_WANT, RED_SNOW, SOMEONE_IS_WAITING, NO_SENSE_OF_SELF, YOU_DO_NOT_MAKE_SENSE, I_FOUND_HER_QUESTION_MARK,
    // part 3
    WHO_IS_SHE, WHAT_ARE_YOU, WHERE_IS_SHE, WHY_WOULD_YOU_DO_THIS, YOU_HAVE_GOT_TO_STOP, DO_NOT_LET_HIM_ESCAPE, NICOLE_DIES, ONE_LAST_PUZZLE,
    // climax. a 24 hour (one day) timer will be triggered for everyone at part one.
    FINAL_CONFRONTATION_PT_1, FINAL_CONFRONTATION_PT_2, FINAL_CONFRONTATION_PT_3, FINAL_CONFRONTATION_PT_4, FINAL_CONFRONTATION_PT_5, FINAL_CONFRONTATION_PT_6,
    // ending!
    NICOLE_IS_SAVED, THIS_IS_NOT_THE_LAST_OF_ME, THERE_IS_ANOTHER,

    // lol they haven't even started
    NOT_STARTED
};
PuzzleStatus get_status(int progress);

// define the actual puzzle piece functions
// part 1
void puzzle_init(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void blackbird(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void dead_eye(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void nothing_is_what_it_seems(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void hallucinations(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void she_is_here(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void gravestone(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void suspicion(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void forgotten(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void logon(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);

// part 2
void lies(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void stalker(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void six_feet(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void in_the_woods(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void there_is_nothing_for_me_to_want(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void red_snow(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void someone_is_waiting(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void no_sense_of_self(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void you_do_not_make_sense(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void i_found_her_question_mark(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);

// part 3 pieces
void who_is_she(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void what_are_you(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void where_is_she(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void why_would_you_do_this(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void you_have_got_to_stop(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void do_not_let_him_escape(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void nicole_dies(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void one_last_puzzle(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);

// climax pieces
void final_confrontation_pt_1(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void final_confrontation_pt_2(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void final_confrontation_pt_3(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void final_confrontation_pt_4(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void final_confrontation_pt_5(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void final_confrontation_pt_6(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);

// ending pieces
void nicole_is_saved(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void this_is_not_the_last_of_me(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);
void there_is_another(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path);

#endif