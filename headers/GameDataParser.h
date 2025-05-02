//
// Created by floron on 5/2/25.
//

#ifndef GAMEDATAPARSER_H
#define GAMEDATAPARSER_H
#include <map>
#include <string>
#include <vector>

#include "CardPack.h"

class GameDataParser {
public:
    GameDataParser() = default;
    static void readLineValues(std::size_t n, std::ifstream& fin, std::vector<int> &output_dest);
    static void parseCardPacks(const std::string &game_data_location, std::map<std::string, CardPack> &out_card_map);
};



#endif //GAMEDATAPARSER_H
