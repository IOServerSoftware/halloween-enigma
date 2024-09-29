#pragma once
#ifndef stalker_maze_h
#define stalker_maze_h

#include <string>
#include <vector>
#include <unordered_map>
#include <random>

enum Direction { NORTH, SOUTH, WEST, EAST, CENTRE, UNKNOWN };
struct Room {
    std::vector<Direction> paths;
    Direction opposite;
    std::unordered_map<int, Direction> origin; // Set to {0, centre} if first room in maze
    bool dead_end;
    int room_number;
};
struct Maze {
    int maze_id;
    std::vector<Room> rooms;
    std::unordered_map<int, Direction> true_ending_room;
    bool monster_released;
    int movement_counter;
};

Direction is_direction(const std::string& input);
std::string direction_to_string(Direction dir);
Direction get_opposite_direction(Direction dir);
std::vector<Direction> generate_random_paths(Direction opposite, std::mt19937& rng);
bool is_dead_end(std::mt19937& rng);
Room generate_room(int room_number, Direction origin_direction, Direction opposite, std::mt19937& rng);
Maze generate_maze(int maze_id, int total_rooms, std::mt19937& rng);
void display_room(const Room& room);
Direction get_player_choice(const Room& room);
bool check_monster(const Maze& maze, int current_room);

#endif