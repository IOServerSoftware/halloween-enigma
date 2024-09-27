#pragma once
#ifndef taunt_h
#define taunt_h

#include <dpp/dpp.h>
#include <string>

// This structure is in order
enum Taunt {
    // initial taunts. they will be a collective "one".
    NICOLE_IS_KIDNAPPED, PLAY_MY_GAME,
    // subsequent taunts every day. there should be 30 of those.
    PLAYING_WITH_HER_LIFE, NICOLE_FAKE_MESSAGE_1, NICOLE_FAKE_MESSAGE_2, NICOLE_FAKE_MESSAGE_3, NICOLE_FAKE_MESSAGE_4,
    TIME_IS_RUNNING_OUT, NICOLE_IS_NOT_GOING_ANYWHERE, NICOLE_THREAT, NICOLE_IN_PAIN, NICOLE_PLEADING, SUSPICIOUS_ACTS,
    GIVE_HER_UP, SHE_IS_DEAD_OR_IS_SHE, WHAT_ARE_YOU_WAITING_FOR, HALFWAY_THROUGH, MORE_PAIN, POWER_DRILL_THREAT, POWER_DRILL_ON_NICOLE,
    NICOLE_REAL_RELAY, SHE_NEEDS_HELP, SHODAN_HACK_1, NICOLE_SCREAMING, SHODAN_HACK_2, ALMOST_THERE, WHAT_ARE_YOU_ALL_DOING,
    NICOLE_BEGS, SHODAN_HACK_3, CHAINSAW_THREAT, ONE_LAST_WARNING,
    // game over taunt.
    NICOLE_IS_DEAD
};

Taunt get_taunt(std::string taunt_call);
#endif