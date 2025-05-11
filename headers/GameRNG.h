//
// Created by floron on 4/29/25.
//

#ifndef GAMERNG_H
#define GAMERNG_H

#include <vector>
#include <map>
#include <memory>
#include <string>
#include <random>

#include "CardPack.h"
#include "Constants.h"

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

    std::string current_pack_name = "INTRO_PACK";
    std::string next_pack_name = "GENERAL_PACK_1";
    int current_card_index = 0;
    int years_in_power = 0;

    void pickNewPack();

public:
    explicit GameRNG(const std::string& game_data_location);
    GameRNG(const std::string& game_data_location, int game_seed_, const std::string &starting_pack);
    // cppcheck-suppress getCurrentPackName
    [[nodiscard]] const std::string& getCurrentPackName() const;
    // cppcheck-suppress getCurrentCardIndex
    [[nodiscard]] int getCurrentCardIndex() const;
    void nextCard(Constants::SwipeDirection direction);
    Card& getCurrentCard();
    Card& getNextCard();
    [[nodiscard]] const std::string& getCurrentPackCardBackLocation();
    // cppcheck-suppress getCardPacksMap
    const std::map<std::string, CardPack>& getCardPacksMap();
    CardPack& getCurrentPack();
    [[nodiscard]] int getValue(Constants::GameRNGValues value) const;
    int getYearsInPower() const;
};



#endif //GAMERNG_H
