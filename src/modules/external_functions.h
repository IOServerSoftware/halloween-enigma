#pragma once
#ifndef external_functions_h
#define external_functions_h

#include <dpp/dpp.h>
#include <sstream>

void handle_puzzle_prompts(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd, std::istringstream& args);
void handle_taunt_prompts(dpp::cluster& bot, const dpp::message_create_t& event, const std::string& cmd);
void increment_progress(std::string& user_progress_path, std::ifstream& current_progress);
void reset_progress(std::string user_container, const dpp::message_create_t& event);
int read_progress(std::string& user_progress_path);

#endif
