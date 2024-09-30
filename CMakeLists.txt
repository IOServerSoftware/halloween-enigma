# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(Enigma)
 
# Add DPP as dependency
add_subdirectory(lib/DPP)
 
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
    src/puzzle/part_2/stalker.cpp
    src/puzzle/part_2/six_feet.cpp
    src/puzzle/part_2/mosaic_prevalence.cpp
    src/puzzle/part_2/there_is_nothing_for_me_to_want.cpp
    src/puzzle/part_2/red_snow.cpp
    src/puzzle/part_2/someone_is_waiting.cpp
    src/puzzle/part_2/no_sense_of_self.cpp
    src/puzzle/part_2/you_do_not_make_sense.cpp
    src/puzzle/part_2/i_found_her_question_mark.cpp

    # part 3
    src/puzzle/part_3/who_is_she.cpp
    src/puzzle/part_3/what_are_you.cpp
    src/puzzle/part_3/where_is_she.cpp
    src/puzzle/part_3/why_would_you_do_this.cpp
    src/puzzle/part_3/you_have_got_to_stop.cpp
    src/puzzle/part_3/do_not_let_him_escape.cpp
    src/puzzle/part_3/nicole_dies.cpp
    src/puzzle/part_3/one_last_puzzle.cpp

    # climax (part 4)
    src/puzzle/part_4/climax.cpp # defines ciphers for below files
    src/puzzle/part_4/final_confrontation_pt_1.cpp
    src/puzzle/part_4/final_confrontation_pt_2.cpp
    src/puzzle/part_4/final_confrontation_pt_3.cpp
    src/puzzle/part_4/final_confrontation_pt_4.cpp
    src/puzzle/part_4/final_confrontation_pt_5.cpp
    src/puzzle/part_4/final_confrontation_pt_6.cpp

    # ending (part 5)
    src/puzzle/part_5/nicole_is_saved.cpp

    # add more pieces as needed... and uncomment those that are finished

    # taunts
    # initial
    src/taunt/initial/nicole_is_kidnapped.cpp
    src/taunt/initial/play_my_game.cpp

    # subsequent
    src/taunt/subsequent/playing_with_her_life.cpp
    src/taunt/subsequent/nicole_fake_message_1.cpp
    src/taunt/subsequent/nicole_fake_message_2.cpp
    src/taunt/subsequent/nicole_fake_message_3.cpp
    src/taunt/subsequent/nicole_fake_message_4.cpp
    src/taunt/subsequent/time_is_running_out.cpp
    src/taunt/subsequent/nicole_is_not_going_anywhere.cpp
    src/taunt/subsequent/nicole_threat.cpp
    src/taunt/subsequent/nicole_in_pain.cpp
    src/taunt/subsequent/nicole_pleading.cpp
    src/taunt/subsequent/suspicious_acts.cpp
    src/taunt/subsequent/give_her_up.cpp
    src/taunt/subsequent/she_is_dead_or_is_she.cpp
    src/taunt/subsequent/what_are_you_waiting_for.cpp
    src/taunt/subsequent/halfway_through.cpp
    src/taunt/subsequent/more_pain.cpp
    src/taunt/subsequent/power_drill_threat.cpp
    src/taunt/subsequent/power_drill_on_bestie.cpp
    src/taunt/subsequent/nicole_real_relay.cpp
    src/taunt/subsequent/she_needs_help.cpp
    src/taunt/subsequent/shodan_hack_1.cpp
    src/taunt/subsequent/nicole_screaming.cpp
    src/taunt/subsequent/shodan_hack_2.cpp
    src/taunt/subsequent/almost_there.cpp
    src/taunt/subsequent/what_are_you_all_doing.cpp
    src/taunt/subsequent/nicole_begs.cpp
    src/taunt/subsequent/shodan_hack_3.cpp
    src/taunt/subsequent/death_threat.cpp
    src/taunt/subsequent/one_last_warning.cpp
    src/taunt/subsequent/nicole_is_dead.cpp

    # add more taunts as needed... and uncomment those that are finished
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