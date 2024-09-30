#pragma once
#ifndef climax_h
#define climax_h

#include <string>
#include <optional>
#include <dpp/dpp.h>

bool is_player_ready(const dpp::message_create_t& event);

struct Cipher {
    std::string cipher_type;
    std::string cipher_text;
    std::string solved_text;
    std::string key;
};

extern Cipher caesar;
extern Cipher rot13;
extern Cipher atbash;
extern Cipher rail_fence;
extern Cipher vigenere;
extern Cipher enigma;

#endif