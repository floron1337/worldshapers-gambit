//
// Created by floron on 4/29/25.
//

#ifndef CARDPACK_H
#define CARDPACK_H

#include <vector>
#include "Card.h"

class CardPack {
    std::string pack_name;
    std::string next_pack_name;

    std::vector<Card> cards;
    bool shuffle_cards = false;
    bool final_pack = false;
public:
    CardPack() = default;
    CardPack(const std::string &pack_name_, const std::vector<Card> &cards_, bool shuffle_cards_, bool final_pack_, const std::string &next_pack_name_);
};


#endif //CARDPACK_H
