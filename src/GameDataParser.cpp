//
// Created by floron on 5/2/25.
//

#include "../headers/GameDataParser.h"

#include <fstream>
#include <iostream>
#include <map>

void GameDataParser::readLineValues(std::size_t n, std::ifstream& fin, std::vector<int> &output_dest) {
    output_dest.resize(n);
    for (std::size_t i = 0; i < n; i++) {
        fin >> output_dest[i];
    }
}

void GameDataParser::parseCardPacks(const std::string &game_data_location, std::map<std::string, CardPack> &out_card_map) {
    std::ifstream fin(game_data_location);
    if (!fin.is_open()) {
        std::cerr << "Failed to open Game Data File\n";
        return;
    }

    while (fin)
    {
        std::string pack_name;
        std::size_t card_cnt;

        fin >> pack_name;
        fin >> card_cnt;
        fin.get();

        std::vector<Card> cards;

        for (std::size_t i = 0; i < card_cnt; i++) {
            std::string card_text;
            std::string card_front_location;
            std::string card_back_location;

            std::getline(fin, card_text);
            std::getline(fin, card_front_location);
            std::getline(fin, card_back_location);

            std::vector<int> card_left_change;
            std::vector<int> card_left_faction_change;
            std::vector<int> card_right_change;
            std::vector<int> card_right_faction_change;

            readLineValues(4, fin, card_left_change);
            readLineValues(4, fin, card_left_faction_change);
            readLineValues(4, fin, card_right_change);
            readLineValues(4, fin, card_right_faction_change);

            Card card(card_left_change, card_left_faction_change, card_right_change, card_right_faction_change, card_text, card_front_location, card_back_location);
            cards.push_back(card);
        }

        CardPack card_pack(pack_name, cards, false, false, "");
        out_card_map[pack_name] = card_pack;
    }
}

