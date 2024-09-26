# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(Enigma)
 
# Add DPP as dependency
add_subdirectory(libs/DPP)
 
# Create an executable
add_executable(enigma
    # main stuff
    src/main.cpp
    src/modules/puzzle.cpp

    # config
    src/cfg/config.cpp
    
    # puzzle pieces
    # src/puzzle/part_#/*.cpp
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