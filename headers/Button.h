// headers/Button.h
#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    std::string btn_text_str;
    sf::Text btn_text;
    sf::RectangleShape btn_shape;
    sf::Font btn_font;
public:
    Button(const std::string &btn_content, float pos_x, float pos_y, float size_x, float size_y, const sf::Font &font, int font_size, const sf::Color &text_color, const sf::Color &bg_color);

    sf::RectangleShape& getShape() {
        return btn_shape;
    }

    sf::Text& getText() {
        return btn_text;
    }
};