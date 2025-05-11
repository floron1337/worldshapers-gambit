//
// Created by floron on 4/11/25.
//

#include <iostream>
#include "../headers/Card.h"

Card::Card(const Card &other)
    : Card(other.card_left_change, other.card_left_faction_change, other.card_right_change, other.card_right_faction_change, other.card_text, other.card_front_location)
{
}

Card& Card::operator=(const Card &other) {
    if (this == &other) {
        return *this;
    }

    card_text = other.card_text;
    card_front_location = other.card_front_location;

    card_left_change = other.card_left_change;
    card_left_faction_change = other.card_left_faction_change;
    card_right_change = other.card_right_change;
    card_right_faction_change = other.card_right_faction_change;

    return *this;
}

Card::Card(const std::vector<int> &card_left_change_,
         const std::vector<int> &card_left_faction_change_,
         const std::vector<int> &card_right_change_,
         const std::vector<int> &card_right_faction_change_,
         const std::string &card_text_,
         const std::string &card_front_location_)
    : card_text(card_text_),
      card_front_location(card_front_location_),
      card_left_change(card_left_change_),
      card_left_faction_change(card_left_faction_change_),
      card_right_change(card_right_change_),
      card_right_faction_change(card_right_faction_change_)
{
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << "Card Text: " << card.getText() << "\n"
       << "Front: " << card.getFrontLocation() << "\n" << std::endl;

    return os;
}

const std::string &Card::getText() const{
    return card_text;
}

const std::string& Card::getFrontLocation() const{
    return card_front_location;
}

std::vector<int>& Card::getLeftChange() {
    return card_left_change;
}

std::vector<int>& Card::getRightChange() {
    return card_right_change;
}

std::vector<int>& Card::getLeftFactionChange() {
    return card_left_faction_change;
}

std::vector<int>& Card::getRightFactionChange() {
    return card_right_faction_change;
}


