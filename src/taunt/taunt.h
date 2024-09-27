#pragma once
#ifndef taunt_h
#define taunt_h

#include <dpp/dpp.h>
#include <string>

// decoy Nicole for fake messages
extern dpp::webhook fake_nicole;

// This structure is in order
enum Taunt {
    // initial taunts. they will be a collective "one".
    NICOLE_IS_KIDNAPPED, PLAY_MY_GAME,
    // subsequent taunts every day. there should be 30 of those.
    PLAYING_WITH_HER_LIFE, NICOLE_FAKE_MESSAGE_1, NICOLE_FAKE_MESSAGE_2, NICOLE_FAKE_MESSAGE_3, NICOLE_FAKE_MESSAGE_4,
    TIME_IS_RUNNING_OUT, NICOLE_IS_NOT_GOING_ANYWHERE, NICOLE_THREAT, NICOLE_IN_PAIN, NICOLE_PLEADING, SUSPICIOUS_ACTS,
    GIVE_HER_UP, SHE_IS_DEAD_OR_IS_SHE, WHAT_ARE_YOU_WAITING_FOR, HALFWAY_THROUGH, MORE_PAIN, POWER_DRILL_THREAT, POWER_DRILL_ON_NICOLE,
    NICOLE_REAL_RELAY, SHE_NEEDS_HELP, SHODAN_HACK_1, NICOLE_SCREAMING, SHODAN_HACK_2, ALMOST_THERE, WHAT_ARE_YOU_ALL_DOING,
    NICOLE_BEGS, SHODAN_HACK_3, DEATH_THREAT, ONE_LAST_WARNING,
    // game over taunt.
    NICOLE_IS_DEAD,
    // there is no taunt.
    NO_TAUNT
};

Taunt get_taunt(std::string taunt_call);

// define taunt functions
void nicole_is_kidnapped(dpp::cluster& bot, const dpp::message_create_t& event);
void play_my_game(dpp::cluster& bot, const dpp::message_create_t& event);
void playing_with_her_life(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_fake_message_1(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_fake_message_2(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_fake_message_3(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_fake_message_4(dpp::cluster& bot, const dpp::message_create_t& event);
void time_is_running_out(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_is_not_going_anywhere(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_threat(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_in_pain(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_pleading(dpp::cluster& bot, const dpp::message_create_t& event);
void suspicious_acts(dpp::cluster& bot, const dpp::message_create_t& event);
void give_her_up(dpp::cluster& bot, const dpp::message_create_t& event);
void she_is_dead_or_is_she(dpp::cluster& bot, const dpp::message_create_t& event);
void what_are_you_waiting_for(dpp::cluster& bot, const dpp::message_create_t& event);
void halfway_through(dpp::cluster& bot, const dpp::message_create_t& event);
void more_pain(dpp::cluster& bot, const dpp::message_create_t& event);
void power_drill_threat(dpp::cluster& bot, const dpp::message_create_t& event);
void power_drill_on_nicole(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_real_relay(dpp::cluster& bot, const dpp::message_create_t& event);
void she_needs_help(dpp::cluster& bot, const dpp::message_create_t& event);
void shodan_hack_1(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_screaming(dpp::cluster& bot, const dpp::message_create_t& event);
void shodan_hack_2(dpp::cluster& bot, const dpp::message_create_t& event);
void almost_there(dpp::cluster& bot, const dpp::message_create_t& event);
void what_are_you_all_doing(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_begs(dpp::cluster& bot, const dpp::message_create_t& event);
void shodan_hack_3(dpp::cluster& bot, const dpp::message_create_t& event);
void death_threat(dpp::cluster& bot, const dpp::message_create_t& event);
void one_last_warning(dpp::cluster& bot, const dpp::message_create_t& event);
void nicole_is_dead(dpp::cluster& bot, const dpp::message_create_t& event);
#endif