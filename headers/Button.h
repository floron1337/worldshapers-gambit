//
// Created by floron on 4/9/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    std::string btn_text_str;
    sf::Text btn_text;
    sf::RectangleShape btn_shape;
    sf::Font btn_font;
public:
    Button(const std::string &btn_text_str, float pos_x, float pos_y, float size_x, float size_y, const sf::Font &font, int font_size, const sf::Color &text_color, const sf::Color &bg_color);
    sf::RectangleShape getShape();
    sf::Text getText();
};



#endif //BUTTON_H
