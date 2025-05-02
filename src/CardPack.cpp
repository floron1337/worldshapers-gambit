//
// Created by floron on 4/29/25.
//

#include "../headers/CardPack.h"

CardPack::CardPack(const std::string &pack_name_, const std::vector<Card> &cards_, bool shuffle_cards_, bool final_pack_, const std::string &next_pack_name_) {
    pack_name = pack_name_;
    cards = cards_;
    shuffle_cards = shuffle_cards_;
    final_pack = final_pack_;
    next_pack_name = next_pack_name_;
}