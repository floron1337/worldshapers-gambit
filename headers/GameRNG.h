//
// Created by floron on 4/29/25.
//

#ifndef GAMERNG_H
#define GAMERNG_H

#include <vector>
#include <map>
#include <string>
#include <random>

#include "CardPack.h"

class GameRNG {
    int finances = 50, popularity = 50, power = 50, industry = 50;
    /*
        Sistemul de factiuni si tot RNG-ul in sine e gandit sa poata fi expandat
        de catre comunitate cu factiuni, pachete si carti custom

        Factiuni default (asa cum se vor gasi in map):
        ECLIPSE
        OMNITERRA
        LEGION
        CULT
    */
    std::map<std::string, CardPack> card_packs;
    std::map<std::string, int> faction_influence;
    int game_seed = 0;

public:
    explicit GameRNG(const std::string& game_data_location);
    GameRNG(const std::string& game_data_location, int game_seed_);
};



#endif //GAMERNG_H
