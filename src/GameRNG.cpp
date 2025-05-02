//
// Created by floron on 4/29/25.
//

#include "../headers/GameRNG.h"

#include "../headers/GameDataParser.h"

GameRNG::GameRNG(const std::string &game_data_location) {
    faction_influence["ECLIPSE"] = 0;
    faction_influence["OMNITERRA"] = 0;
    faction_influence["LEGION"] = 0;
    faction_influence["CULT"] = 0;

    GameDataParser::parseCardPacks(game_data_location, card_packs);

    // LINIE DE COD INUTILA ADAUGATA MOMENTAN CA SA COMPILEZE
    industry++, popularity++, power++, finances++;
}

GameRNG::GameRNG(const std::string &game_data_location, int game_seed_) : GameRNG(game_data_location) {
    game_seed = game_seed_;
}

