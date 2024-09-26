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

    # config
    src/cfg/config.cpp
    
    # puzzle pieces
    # template below
    # src/puzzle/part_#/*.cpp

    # part 1
    src/puzzle/part_1/start.cpp
    # add more pieces as needed...
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