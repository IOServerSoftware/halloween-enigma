#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <filesystem>
#include "stalker_maze.h" // defines functions needed for maze generation/load
#include "../puzzle.h"
#include "../../cfg/config.h"
#include "../../modules/external_functions.h"

namespace fs = std::filesystem;

void stalker(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    int current = read_progress(user_progress_path);
    uint64_t seed = static_cast<uint64_t>(event.msg.author.id) + static_cast<uint64_t>(event.msg.channel_id) + static_cast<uint64_t>(std::time(0));

    if (current == 12 && !fs::exists(__user_progress_container(event.msg.author.id))) {
        std::ofstream maze_entered(__user_progress_container(event.msg.author.id)+"_maze.txt");
        event.send("```You're in a maze. Four directions are available to you.\nYou only see when you want to see.\nWhere do you want to go?\n\n(north/south/east/west)```");
    }

    if (current == 12 && fs::exists(__user_progress_container(event.msg.author.id)) && is_direction(event.msg.content.substr(prefix.length()))) {
        std::cout << "[EXTERNAL CONSOLE IO] User is trying to move in the maze. Trying..." << std::endl;
        // Read from maze, then determine if it is moveable.
        // If, instead, "look" is defined, print the possible directions
        // as if it's a 70s text-based adventure game.
    }
}