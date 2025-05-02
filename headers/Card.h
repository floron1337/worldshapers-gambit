//
// Created by floron on 4/11/25.
//

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class Card {
    std::string card_text = "";
    std::string card_front_location = "./images/cards/placeholder.png";
    std::string card_back_location = "./images/cards/placeholder.png";

    std::vector<int> card_left_change = {0, 0, 0, 0};
    std::vector<int> card_left_faction_change = {0, 0, 0, 0};
    std::vector<int> card_right_change = {0, 0, 0, 0};
    std::vector<int> card_right_faction_change = {0, 0, 0, 0};

public:
    Card() = default;
    Card(const std::vector<int> &card_left_change_,
         const std::vector<int> &card_left_faction_change_,
         const std::vector<int> &card_right_change_,
         const std::vector<int> &card_right_faction_change_,
         const std::string &card_text_,
         const std::string &card_front_location_,
         const std::string &card_back_location_);
    Card(const Card &other);
    Card &operator=(const Card &other);
    //~Card();

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    [[nodiscard]]const std::string& getFrontLocation() const;
    [[nodiscard]]const std::string& getBackLocation() const;
    [[nodiscard]]const std::string& getText() const;
};



#endif //CARD_H
