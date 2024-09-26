#include "commands.h"
#include <dpp/dpp.h>
#include <iostream>
#include <fstream>
#include <filesystem>

// Separate function for handling prefix-based commands
void handle_prefix_command(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd, std::istringstream& args) {
    if (cmd == "start") {
        //
    } else if (cmd == "approve") {
        //
    } else {
        return; // don't do anything
    }
}
