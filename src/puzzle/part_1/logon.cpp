#include "../puzzle.h"
#include "../../modules/external_functions.h"
#include "../../cfg/config.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

enum Manifesto { DECEMBER, OCTOBER, NOVEMBER, MAY, FEBRUARY, UNDEFINED };
Manifesto pick_manifesto(const std::string& message) {
    if (message == "december" || message == "December" || message == "DECEMBER") return DECEMBER;
    if (message == "october" || message == "October" || message == "OCTOBER") return OCTOBER;
    if (message == "november" || message == "November" || message == "NOVEMBER") return NOVEMBER;
    if (message == "may" || message == "May" || message == "MAY") return MAY;
    if (message == "february" || message == "February" || message == "FEBRUARY") return FEBRUARY;
    return UNDEFINED;
}

std::unordered_map<Manifesto, std::string> manifesto_messages = {
    { DECEMBER, "```15TH DECEMBER 1993\nDAY OF RECKONING\nThe first anniversary celebration of the DAY of RECKONING was brilliant! Everyone involved would be happy at the work they put into this.\nThis will not be the last of its celebration.\n- Peter Stahelski```" },
    { OCTOBER, "```18TH OCTOBER 2001\nVICTORY!\nNo more lies! We've finally done it now, BROTHERS! This will be the very end of CORRUPTION. We shall celebrate with lights and our newfound POWER. Fight on!\n- Unknown militant unit```" },
    { NOVEMBER, "```7TH NOVEMBER 2001\ndeath to our beloved.\nWe regret to inform you that Peter Stahelski, the leader of the Day of Reckoning, has passed this very moment at 12:53 hours. This man has been the subject of many defeated criminals— the stature of a hero, better than anyone has ever imagined. A new leader named [REDACTED] will take his place. We believe that with him, this nation may be rebuilt to its former glory, and that no crime shall come out of this beloved CITY.\n- Official statement from the government of [REDACTED]```" },
    { MAY, "```15TH MAY 2004\nA case nobody notices\nI'm right outside their house right now... hm, looks like the father looks at the pregnancy test in happiness to his wife. They're excited. Something tells me they're playing a con game here... it could be something else behind the scenes. Nobody knows.\n- [REDACTED]```" },
    { FEBRUARY, "```18TH FEBRUARY 2005\nThe exorcist of the omen\n\n\n\n\n\n\n\nTHEY HAVE FINALLY GIVEN BIRTH.```" }
};

bool are_manifestos_viewed(const dpp::message_create_t& event) {
    if (fs::exists(__user_progress_container(event.msg.author.id)+"_dec.txt") && fs::exists(__user_progress_container(event.msg.author.id)+"_oct.txt") && fs::exists((__user_progress_container(event.msg.author.id)+"_nov.txt"))) return true;
    else return false;
}

void handle_manifesto(dpp::cluster& bot, const dpp::message_create_t& event, Manifesto manifesto, const std::string& user_id) {
    std::string file_path = __user_progress_container(event.msg.author.id);

    // Check if the user has already viewed this manifesto
    std::string manifesto_suffix;
    switch (manifesto) {
        case DECEMBER: manifesto_suffix = "_dec.txt"; break;
        case OCTOBER: manifesto_suffix = "_oct.txt"; break;
        case NOVEMBER: manifesto_suffix = "_nov.txt"; break;
        case MAY: manifesto_suffix = "_may.txt"; break;
        case FEBRUARY: manifesto_suffix = "_feb.txt"; break;
        default: return; // Not a handled manifesto
    }

    if (!fs::exists(file_path + manifesto_suffix)) {
        std::ofstream viewed_file(file_path + manifesto_suffix);
        viewed_file << "1";
        viewed_file.close();
    }
}

void logon(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    std::string user_id = std::to_string(event.msg.author.id);

    if (current == 10 && event.msg.content.substr(prefix.length()) == "INITIATION: CREATE USER ACCOUNT AND AUTO-LOGIN AFTER SUCCESS.") {
        if (!fs::exists(__user_progress_container(event.msg.author.id)+"_logged-on.txt")) {
            std::ofstream logon_status(__user_progress_container(event.msg.author.id)+"_logged-on.txt");
            logon_status << "1";
            logon_status.close();
        }
        event.send("```WELCOME, " + event.msg.author.global_name + ".\nLook through the files here by calling their month.```");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        event.send("```1. 15TH DECEMBER 1993\n2. 18TH OCTOBER 2001\n3. 7TH NOVEMBER 2008\n4. 15TH MAY 2004\n5. 18TH FEBRUARY 2005```");
        std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
        bot.message_delete(event.msg.id, event.msg.channel_id);
        return;
    }

    if (current == 10 && fs::exists(__user_progress_container(event.msg.author.id)+"_logged-on.txt")) {
        Manifesto manifesto = pick_manifesto(event.msg.content.substr(prefix.length()));

        if (manifesto != UNDEFINED && manifesto != MAY && manifesto != FEBRUARY) {
            handle_manifesto(bot, event, manifesto, user_id);
            event.send(manifesto_messages[manifesto]);
            bot.message_delete(event.msg.id, event.msg.channel_id);
            return;
        }

        // Check for the MAY case with previous manifesto checks
        if (manifesto == MAY) {
            if (are_manifestos_viewed(event)) {
                if (!fs::exists(__user_progress_container(event.msg.author.id) + "_may.txt")) {
                    std::ofstream may_viewed(__user_progress_container(event.msg.author.id) + "_may.txt");
                    may_viewed << "1";
                    may_viewed.close();
                }
                event.send(manifesto_messages[MAY]);
                bot.message_delete(event.msg.id, event.msg.channel_id);
            } else {
                event.send("```You do not have the permission to look through this manifesto.```");
                bot.message_delete(event.msg.id, event.msg.channel_id);
            }
        }

        // Check for the FEBRUARY case with previous manifesto checks
        if (manifesto == FEBRUARY) {
            if (fs::exists(__user_progress_container(event.msg.author.id) + "_may.txt")) {
                event.send(manifesto_messages[FEBRUARY]);
                std::ifstream check_progress(user_progress_path);
                increment_progress(user_progress_path, check_progress);
                check_progress.close();
                std::this_thread::sleep_for(std::chrono::seconds(5));
                event.send("```ERR0R. ERROR. POTENT1AL LI3S DE7ECTED.\nINVOKE ERR0R CODE: MORALI7Y_C0MPROMI5ED```"); // 01370705
                std::cout << "[EXTERNAL CONSOLE IO] Puzzle " << current << " deployed." << std::endl;
                bot.message_delete(event.msg.id, event.msg.channel_id);
            } else {
                event.send("```You do not have the permission to look through this manifesto.```");
                bot.message_delete(event.msg.id, event.msg.channel_id);
            }
        }
    }
}
