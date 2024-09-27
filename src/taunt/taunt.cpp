#include "taunt.h"
#include <string>

Taunt get_taunt(std::string taunt_call) {
    // initial
    if (taunt_call == "kidnapped") return NICOLE_IS_KIDNAPPED;
    if (taunt_call == "play game") return PLAY_MY_GAME;

    // subsequent
    if (taunt_call == "play with her life") return PLAYING_WITH_HER_LIFE;
    if (taunt_call == "fake message 1") return NICOLE_FAKE_MESSAGE_1;
    if (taunt_call == "fake message 2") return NICOLE_FAKE_MESSAGE_2;
    if (taunt_call == "fake message 3") return NICOLE_FAKE_MESSAGE_3;
    if (taunt_call == "fake message 4") return NICOLE_FAKE_MESSAGE_4;
    if (taunt_call == "time running out") return TIME_IS_RUNNING_OUT;
    if (taunt_call == "not going anywhere") return NICOLE_IS_NOT_GOING_ANYWHERE;
    if (taunt_call == "threaten") return NICOLE_THREAT;
    if (taunt_call == "nicole hurt") return NICOLE_IN_PAIN;
    if (taunt_call == "she pleads") return NICOLE_PLEADING;
    if (taunt_call == "something is happening...") return SUSPICIOUS_ACTS;
    if (taunt_call == "give up") return GIVE_HER_UP;
    if (taunt_call == "dead?") return SHE_IS_DEAD_OR_IS_SHE;
    if (taunt_call == "wait") return WHAT_ARE_YOU_WAITING_FOR;
    if (taunt_call == "halfway") return HALFWAY_THROUGH;
    if (taunt_call == "more pain") return MORE_PAIN;
    if (taunt_call == "brrr") return POWER_DRILL_THREAT;
    if (taunt_call == "buzz") return POWER_DRILL_ON_NICOLE;
    if (taunt_call == "relay") return NICOLE_REAL_RELAY;
    if (taunt_call == "help") return SHE_NEEDS_HELP;
    if (taunt_call == "shodan 1") return SHODAN_HACK_1;
    if (taunt_call == "ahh") return NICOLE_SCREAMING;
    if (taunt_call == "shodan 2") return SHODAN_HACK_2;
    if (taunt_call == "almost") return ALMOST_THERE;
    if (taunt_call == "wtf") return WHAT_ARE_YOU_ALL_DOING;
    if (taunt_call == "nicole begs") return NICOLE_BEGS;
    if (taunt_call == "shodan 3") return SHODAN_HACK_3;
    if (taunt_call == "texas") return CHAINSAW_THREAT;
    if (taunt_call == "last day") return ONE_LAST_WARNING;

    // game over
    if (taunt_call == "game over") return NICOLE_IS_DEAD;
}