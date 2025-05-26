//
// Created by floron on 5/2/25.
//

#include "../headers/GameDataParser.h"
#include "../headers/Exception.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>

void GameDataParser::readLineValues(std::size_t n, std::ifstream& fin, std::vector<int> &output_dest) {
    output_dest.resize(n);
    for (std::size_t i = 0; i < n; i++) {
        fin >> output_dest[i];
    }
    fin.get();
}

void GameDataParser::parseCardPacks(const std::string &game_data_location, std::map<std::string, CardPack> &out_card_map) {
    std::ifstream fin(game_data_location);
    if (!fin.is_open()) {
        throw MissingGameData();
    }

    while (fin)
    {
        std::string pack_name;
        std::string pack_back_location;
        std::size_t card_cnt;

        fin >> pack_name;
        fin.get();
        std::getline(fin, pack_back_location);

        bool final_pack = false;
        std::string next_pack_name;

        if (pack_back_location[0] == '!') {
            final_pack = true;
            std::getline(fin, pack_back_location);
        }
        else if (pack_back_location[0] == '@') {
            next_pack_name = pack_back_location.substr(1);
            std::getline(fin, pack_back_location);
        }

        fin >> card_cnt;
        fin.get();

        std::vector<Card> cards;

        for (std::size_t i = 0; i < card_cnt; i++) {
            std::string card_text;
            std::string card_front_location;

            // functie ajutatoare sa imi citeasca \n cum trebuie
            std::getline(fin, card_text);
            size_t pos = 0;
            while ((pos = card_text.find("\\n", pos)) != std::string::npos) {
                card_text.replace(pos, 2, "\n");
                pos += 1;
            }

            std::getline(fin, card_front_location);

            std::vector<int> card_left_change;
            std::vector<int> card_left_faction_change;
            std::vector<int> card_right_change;
            std::vector<int> card_right_faction_change;

            readLineValues(4, fin, card_left_change);
            readLineValues(4, fin, card_left_faction_change);
            readLineValues(4, fin, card_right_change);
            readLineValues(4, fin, card_right_faction_change);

            Card card(card_left_change, card_left_faction_change, card_right_change, card_right_faction_change, card_text, card_front_location);
            cards.push_back(card);
        }

        CardPack card_pack(pack_name, pack_back_location, cards, final_pack, next_pack_name);
        out_card_map[pack_name] = card_pack;
    }
}

