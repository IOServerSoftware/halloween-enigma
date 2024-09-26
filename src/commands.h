#pragma once
#ifndef commands_h
#define commands_h

#include <dpp/dpp.h>
#include <sstream>

void handle_prefix_command(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd, std::istringstream& args);

#endif
