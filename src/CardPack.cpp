//
// Created by floron on 4/29/25.
//

#include "../headers/CardPack.h"

#include <iostream>

CardPack::CardPack(const std::string &pack_name_,
                   const std::string &pack_cards_back_location_,
                   const std::vector<Card> &cards_,
                   bool final_pack_,
                   const std::string &next_pack_name_)
    : pack_name(pack_name_),
      pack_cards_back_location(pack_cards_back_location_),
      next_pack_name(next_pack_name_),
      cards(cards_),
      final_pack(final_pack_)
{
}

Card& CardPack::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(cards.size())) {
        throw std::out_of_range("CardPack::operator[] – invalid card index");
    }

    return cards[index];
}

const std::string& CardPack::getPackCardBackLocation() {
    return pack_cards_back_location;
}

int CardPack::size() const noexcept {
    return static_cast<int>(cards.size());
}

bool CardPack::isFinalPack() const {
    return final_pack;
}

const std::string& CardPack::getNextPackName() const{
    return next_pack_name;
}