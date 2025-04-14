//
// Created by floron on 4/11/25.
//

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    std::string card_text = "";
    std::string card_front_location = "../images/cards/placeholder.png";
    std::string card_back_location = "../images/cards/placeholder.png";

    Card * next_card = nullptr;
public:
    Card();
    Card(const std::string &card_text_, const std::string &card_front_location_, const std::string &card_back_location_);
    Card(const Card &other);
    Card &operator=(const Card &other);
    ~Card();

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    std::string getFrontLocation() const;
    std::string getBackLocation() const;
    [[nodiscard]] std::string getText() const;
};



#endif //CARD_H
