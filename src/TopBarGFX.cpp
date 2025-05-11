//
// Created by floron on 5/10/25.
//

#include "../headers/TopBarGFX.h"

#include <iostream>

TopBarGFX::TopBarGFX(sf::RenderWindow &window_, GameRNG &game_rng_) : window(window_), game_rng(game_rng_) {
    if (!finance_texture.loadFromFile("./images/finance_icon.png") ) {
        std::cerr << "Failed to load finance icon texture" << std::endl;
    }
    else {
        finance_sprite.setTexture(finance_texture);
        finance_sprite_back.setTexture(finance_texture);
    }
    if (!popularity_texture.loadFromFile("./images/popularity_icon.png") ) {
        std::cerr << "Failed to load finance icon texture" << std::endl;
    }
    else {
        popularity_sprite.setTexture(popularity_texture);
        popularity_sprite_back.setTexture(popularity_texture);
    }
    if (!power_texture.loadFromFile("./images/power_icon.png") ) {
        std::cerr << "Failed to load finance icon texture" << std::endl;
    }
    else {
        power_sprite.setTexture(power_texture);
        power_sprite_back.setTexture(power_texture);
    }
    if (!industry_texture.loadFromFile("./images/industry_icon.png") ) {
        std::cerr << "Failed to load finance icon texture" << std::endl;
    }
    else {
        industry_sprite.setTexture(industry_texture);
        industry_sprite_back.setTexture(industry_texture);
    }
}

void TopBarGFX::drawTopBarElement(sf::Texture &texture, sf::Sprite &sprite, sf::Sprite &sprite_back, float x_pos, float scale, int value, int card_change) {
    sprite_back.setScale(scale, scale);
    sf::FloatRect bounds_back = sprite_back.getLocalBounds();
    sprite_back.setOrigin(bounds_back.width / 2.f,  bounds_back.height);
    sprite_back.setPosition(x_pos, 45.0f);
    sf::Color color = sprite_back.getColor();
    color.a = 64;
    sprite_back.setColor(color);
    sprite_back.setRotation(180);

    sprite.setScale(scale, scale);

    sf::IntRect texRect = sprite.getTextureRect();
    texRect.width = texture.getSize().x;
    texRect.height = static_cast<int>(texture.getSize().y * value / 100.0f);
    sprite.setTextureRect(texRect);

    sf::FloatRect bounds = sprite_back.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height);
    sprite.setPosition(x_pos, 45.0f);
    sprite.setRotation(180);

    window.draw(sprite_back);
    window.draw(sprite);

    if (card_change != 0) {
        float radius = card_change < 25 ? 10.0f : 20.0f;
        sf::CircleShape change_rect(radius);
        change_rect.setFillColor(sf::Color::White);
        change_rect.setPosition(x_pos, 140.0f);
        change_rect.setRotation(180);
        change_rect.setScale(scale, scale);
        window.draw(change_rect);
    }
}


void TopBarGFX::draw(int mouseX) {
    int windowX = window.getSize().x;
    Card& current_card = game_rng.getCurrentCard();
    std::vector<int> &current_card_change = (mouseX < windowX / 2.0f) ? current_card.getLeftChange() : current_card.getRightChange();

    drawTopBarElement(finance_texture, finance_sprite, finance_sprite_back, windowX / 2 - 225, 0.4f, game_rng.getValue(Constants::GameRNGValues::Finances), current_card_change[0]);
    drawTopBarElement(popularity_texture, popularity_sprite, popularity_sprite_back, windowX / 2 - 75, 0.4f, game_rng.getValue(Constants::GameRNGValues::Popularity), current_card_change[1]);
    drawTopBarElement(power_texture, power_sprite, power_sprite_back, windowX / 2.0f + 75, 0.4f, game_rng.getValue(Constants::GameRNGValues::Power), current_card_change[2]);
    drawTopBarElement(industry_texture, industry_sprite,industry_sprite_back, windowX / 2.0f + 225, 0.4f, game_rng.getValue(Constants::GameRNGValues::Industry), current_card_change[3]);
}
