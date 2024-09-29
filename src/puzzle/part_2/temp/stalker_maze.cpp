#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <unordered_map>
#include "stalker_maze.h"
#include "../puzzle.h"

namespace fs = std::filesystem;

std::string north_iterations[] = { "north", "North", "NORTH", "n", "N" };
std::string south_iterations[] = { "south", "South", "SOUTH", "s", "S" };
std::string west_iterations[] = { "west", "West", "WEST", "W", "W" };
std::string east_iterations[] = { "east", "East", "EAST", "e", "E" };

Direction is_direction(const std::string& input) {
    // North
    for (int i = 0; i < sizeof(north_iterations) / sizeof(north_iterations[0]); i++) {
        if (north_iterations[i] == input) {
            return NORTH;
        }
    }
    // South
    for (int i = 0; i < sizeof(south_iterations) / sizeof(south_iterations[0]); i++) {
        if (south_iterations[i] == input) {
            return SOUTH;
        }
    }
    // West
    for (int i = 0; i < sizeof(west_iterations) / sizeof(west_iterations[0]); i++) {
        if (west_iterations[i] == input) {
            return WEST;
        }
    }
    // East
    for (int i = 0; i < sizeof(east_iterations) / sizeof(east_iterations[0]); i++) {
        if (east_iterations[i] == input) {
            return EAST;
        }
    }
}

// Utility to convert direction to string
std::string direction_to_string(Direction dir) {
    switch (dir) {
        case NORTH: return "north";
        case SOUTH: return "south";
        case EAST: return "east";
        case WEST: return "west";
        case CENTRE: return "centre";
        case UNKNOWN: return "unknown";
        default: return "";
    }
}

// Get the opposite direction for backtracking
Direction get_opposite_direction(Direction dir) {
    switch (dir) {
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST: return WEST;
        case WEST: return EAST;
        default: return UNKNOWN;
    }
}

// Save a room's state to a file for persistence
void save_room(const Room& room, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Room " << room.room_number << "\n";
        file << "Dead End: " << room.dead_end << "\n";
        file << "Paths: ";
        for (const auto& path : room.paths) {
            file << direction_to_string(path) << " ";
        }
        file << "\n";
        file << "Opposite Direction: " << direction_to_string(room.opposite) << "\n";
        file.close();
    }
}

// Generate random directions for the room, avoiding the opposite direction
std::vector<Direction> generate_random_paths(Direction opposite, std::mt19937& rng) {
    std::vector<Direction> available_directions = {NORTH, SOUTH, EAST, WEST};
    std::vector<Direction> selected_paths;

    // Remove the opposite direction from available options
    available_directions.erase(std::remove(available_directions.begin(), available_directions.end(), opposite), available_directions.end());

    std::shuffle(available_directions.begin(), available_directions.end(), rng);
    int num_paths = std::uniform_int_distribution<int>(2, 3)(rng);  // Rooms have 2 or 3 paths

    for (int i = 0; i < num_paths; ++i) {
        selected_paths.push_back(available_directions[i]);
    }
    return selected_paths;
}

// Check if a room is a dead end (random chance)
bool is_dead_end(std::mt19937& rng) {
    return std::uniform_int_distribution<int>(1, 10)(rng) == 1;  // 1 in 10 chance for dead end
}

// Generate a room with random paths, avoiding the opposite direction
Room generate_room(int room_number, Direction origin_direction, Direction opposite, std::mt19937& rng) {
    Room room;
    room.room_number = room_number;
    room.opposite = opposite;
    room.dead_end = is_dead_end(rng);

    // Set the origin for this room (with room number as the key)
    room.origin[room_number] = origin_direction;

    // Generate paths, avoiding the opposite direction
    if (!room.dead_end) {
        room.paths = generate_random_paths(opposite, rng);
    } else {
        room.paths.clear();  // Dead end room has no paths
    }

    // Save the generated room to a file for persistence
    std::string filename = "room_" + std::to_string(room_number) + ".txt";
    save_room(room, filename);

    return room;
}

// Initialize a maze with a given ID
Maze generate_maze(int maze_id, int total_rooms, std::mt19937& rng) {
    Maze maze;
    maze.maze_id = maze_id;
    maze.monster_released = false;
    maze.movement_counter = 0;

    // Generate the first room, with origin set to CENTRE
    Room first_room = generate_room(0, CENTRE, UNKNOWN, rng);  // First room has no opposite
    maze.rooms.push_back(first_room);

    for (int i = 1; i < total_rooms; ++i) {
        Direction origin_direction = UNKNOWN;
        Direction opposite_direction = UNKNOWN;

        if (!maze.rooms.empty()) {
            // Pick a random direction from the previous room's paths
            const Room& last_room = maze.rooms.back();
            if (!last_room.paths.empty()) {
                origin_direction = last_room.paths[std::uniform_int_distribution<int>(0, last_room.paths.size() - 1)(rng)];
                opposite_direction = get_opposite_direction(origin_direction);
            }
        }

        Room new_room = generate_room(i, origin_direction, opposite_direction, rng);
        maze.rooms.push_back(new_room);
    }

    // Randomly assign the true ending room within the last 10 rooms
    int true_end_index = std::uniform_int_distribution<int>(total_rooms - 10, total_rooms - 1)(rng);
    maze.true_ending_room[true_end_index] = UNKNOWN;  // Mark the true ending room

    return maze;
}

void display_room(const Room& room) {
    std::cout << "You are in a room with paths leading to: ";
    for (const auto& path : room.paths) {
        std::cout << direction_to_string(path) << " ";
    }
    std::cout << "\n";
    if (room.dead_end) {
        std::cout << "This is a dead end.\n";
    }
}

Direction get_player_choice(const Room& room) {
    std::string input;
    std::cout << "Choose a direction (north, south, east, west): ";
    std::cin >> input;

    if (input == "north") return NORTH;
    if (input == "south") return SOUTH;
    if (input == "east") return EAST;
    if (input == "west") return WEST;

    std::cout << "Invalid direction. Please choose again.\n";
    return UNKNOWN;
}

bool check_monster(const Maze& maze, int current_room) {
    if (maze.monster_released) {
        std::cout << "The monster is chasing you!\n";
        if (current_room == 0) {
            std::cout << "You've returned to the origin! The monster catches you. Game over!\n";
            return true;
        }
    }
    return false;
}