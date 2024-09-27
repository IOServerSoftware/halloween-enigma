# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(Enigma)
 
# Add DPP as dependency
add_subdirectory(lib/DPP)

# Include puzzle directory so it picks up `puzzle.h`
include_directories(src/puzzle)
 
# Create an executable
add_executable(enigma
    # main stuff
    src/main.cpp
    src/modules/external_functions.cpp
    src/puzzle/puzzle.cpp
    src/taunt/taunt.cpp

    # config
    src/cfg/config.cpp
    
    # puzzle pieces
    # part 1
    src/puzzle/part_1/start.cpp
    src/puzzle/part_1/blackbird.cpp
    src/puzzle/part_1/dead_eye.cpp
    src/puzzle/part_1/nothing_is_what_it_seems.cpp
    src/puzzle/part_1/hallucinations.cpp
    src/puzzle/part_1/she_is_here.cpp
    src/puzzle/part_1/gravestone.cpp
    src/puzzle/part_1/suspicion.cpp
    src/puzzle/part_1/forgotten.cpp
    src/puzzle/part_1/logon.cpp

    # part 2
    src/puzzle/part_2/lies.cpp
    # add more pieces as needed...

    # taunts
    # initial
    src/taunt/initial/nicole_is_kidnapped.cpp
    src/taunt/initial/play_my_game.cpp

    # subsequent
    src/taunt/subsequent/playing_with_her_life.cpp
    src/taunt/subsequent/nicole_fake_message_1.cpp
    src/taunt/subsequent/nicole_fake_message_2.cpp
    src/taunt/subsequent/nicole_fake_message_3.cpp
    # add more taunts as needed...
)
 
# Linking libraries
target_link_libraries(enigma
    dpp
)
 
# Specify includes
target_include_directories(enigma PRIVATE
    libs/DPP/include
)
 
# Set C++ version
set_target_properties(enigma PROPERTIES
    CXX_STANDARD 17 # or 20 if you want something more recent
    CXX_STANDARD_REQUIRED ON
)