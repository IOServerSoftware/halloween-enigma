#pragma once
#ifndef puzzle_h
#define puzzle_h

#include <dpp/dpp.h>

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
    NICOLE_IS_SAVED, THIS_IS_NOT_THE_LAST_OF_ME,

    // lol they haven't even started
    NOT_STARTED
};

PuzzleStatus get_status(int progress) {
    switch (progress) {
        case 1: return START;
        case 2: return BLACKBIRD;
        case 3: return DEAD_EYE;
        case 4: return NOTHING_IS_WHAT_IT_SEEMS;
        case 5: return HALLUCINATIONS;
        case 6: return SHE_IS_HERE;
        case 7: return GRAVESTONE;
        case 8: return SUSPICION;
        case 9: return FORGOTTEN;
        case 10: return LOGON;
        case 11: return LIES;
        case 12: return STALKER;
        case 13: return SIX_FEET;
        case 14: return IN_THE_WOODS;
        case 15: return THERE_IS_NOTHING_FOR_ME_TO_WANT;
        case 16: return RED_SNOW;
        case 17: return SOMEONE_IS_WAITING;
        case 18: return NO_SENSE_OF_SELF;
        case 19: return YOU_DO_NOT_MAKE_SENSE;
        case 20: return I_FOUND_HER_QUESTION_MARK;
        case 21: return WHO_IS_SHE;
        case 22: return WHAT_ARE_YOU;
        case 23: return WHERE_IS_SHE;
        case 24: return WHY_WOULD_YOU_DO_THIS;
        case 25: return YOU_HAVE_GOT_TO_STOP;
        case 26: return DO_NOT_LET_HIM_ESCAPE;
        case 27: return NICOLE_DIES;
        case 28: return ONE_LAST_PUZZLE;
        case 29: return FINAL_CONFRONTATION_PT_1;
        case 30: return FINAL_CONFRONTATION_PT_2;
        case 31: return FINAL_CONFRONTATION_PT_3;
        case 32: return FINAL_CONFRONTATION_PT_4;
        case 33: return FINAL_CONFRONTATION_PT_5;
        case 34: return FINAL_CONFRONTATION_PT_6;
        case 35: return NICOLE_IS_SAVED;
        case 36: return THIS_IS_NOT_THE_LAST_OF_ME;
        default: return NOT_STARTED;
    }
}

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

#endif