//
// Created by floron on 4/29/25.
//

#ifndef CARDPACK_H
#define CARDPACK_H

#include <vector>
#include "Card.h"

class CardPack {
    std::string pack_name;
    std::string pack_cards_back_location = "back.png";
    std::string next_pack_name;

    std::vector<Card> cards;
    bool final_pack = false;
public:
    CardPack() = default;
    CardPack(const std::string &pack_name_, const std::string &pack_cards_back_location_, const std::vector<Card> &cards_, bool final_pack_, const std::string &next_pack_name_);
    Card& operator[](int index);
    [[nodiscard]] int size() const noexcept;
    const std::string& getPackCardBackLocation();
    bool isFinalPack() const;
};


#endif //CARDPACK_H
