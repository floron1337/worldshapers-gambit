//
// Created by floron on 4/11/25.
//

#include <iostream>
#include "../headers/Card.h"

Card::Card()
    : card_text(""),
      card_front_location("images/cards/placeholder.png"),
      card_back_location("images/cards/back.png")
{
}


Card::Card(const Card &other)
    : card_text(other.card_text),
      card_front_location(other.card_front_location),
      card_back_location(other.card_back_location)
{

}

Card& Card::operator=(const Card &other) {
    if (this == &other) {
        return *this;
    }

    card_text = other.card_text;
    card_front_location = other.card_front_location;
    card_back_location = other.card_back_location;
    next_card = other.next_card; // dubios

    return *this;
}

Card::~Card() {
    delete next_card;
    next_card = nullptr;
}

Card::Card(const std::string &card_text_,
           const std::string &card_front_location_,
           const std::string &card_back_location_)
    : card_text(card_text_),
      card_front_location(card_front_location_),
      card_back_location(card_back_location_)
{

}


std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << "Card Text: " << card.getText() << "\n"
       << "Front: " << card.getFrontLocation() << "\n"
       << "Back: " << card.getBackLocation() << std::endl;

    return os;
}

const std::string &Card::getText() const{
    return card_text;
}

const std::string& Card::getFrontLocation() const{
    return card_front_location;
}

const std::string& Card::getBackLocation() const{
    return card_back_location;
}
