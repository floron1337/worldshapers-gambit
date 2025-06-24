//
// Created by floron on 6/24/25.
//

#include "../headers/Button.h"

Button::Button(const std::string &btn_content, float pos_x, float pos_y, float size_x, float size_y, const sf::Font &font, int font_size, const sf::Color &text_color, const sf::Color &bg_color)
        : btn_text_str(btn_content), btn_shape(sf::Vector2f(size_x, size_y))
{
    btn_shape.setFillColor(bg_color);
    btn_shape.setOrigin(btn_shape.getSize() / 2.0f);
    btn_shape.setPosition(pos_x, pos_y);

    btn_text = sf::Text(btn_text_str, font, font_size);
    btn_text.setFillColor(text_color);
    sf::FloatRect btn_text_bounds = btn_text.getLocalBounds();
    btn_text.setOrigin(
        btn_text_bounds.left + btn_text_bounds.width / 2.0f,
        btn_text_bounds.top + btn_text_bounds.height / 2.0f
    );
    btn_text.setPosition(btn_shape.getPosition());
}