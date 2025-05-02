//
// Created by floron on 4/29/25.
//

#include "../headers/CardPack.h"

CardPack::CardPack(const std::string &pack_name_,
                   const std::vector<Card> &cards_,
                   bool shuffle_cards_,
                   bool final_pack_,
                   const std::string &next_pack_name_)
    : pack_name(pack_name_),        // copies (or moves) directly into the member
      next_pack_name(next_pack_name_),                // idem
      cards(cards_),// direct initialization for built-ins
      shuffle_cards(shuffle_cards_),      // —
      final_pack(final_pack_)
{


    // TODO: COD INUTIL CA SA COMPILEZE, O SA FIE IMPLEMENTATE MAI TARZIU
    final_pack = true;
    shuffle_cards = true;
}
