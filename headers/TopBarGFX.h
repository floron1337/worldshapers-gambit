//
// Created by floron on 5/10/25.
//

#ifndef TOPBARGFX_H
#define TOPBARGFX_H
#include "GameRNG.h"
#include "SFML/Graphics.hpp"


class TopBarGFX {
    GameRNG &game_rng;
    sf::RenderWindow &window;

    sf::Texture finance_texture;
    sf::Sprite finance_sprite;
    sf::Sprite finance_sprite_back;

    sf::Texture popularity_texture;
    sf::Sprite popularity_sprite;
    sf::Sprite popularity_sprite_back;

    sf::Texture power_texture;
    sf::Sprite power_sprite;
    sf::Sprite power_sprite_back;

    sf::Texture industry_texture;
    sf::Sprite industry_sprite;
    sf::Sprite industry_sprite_back;

public:
    explicit TopBarGFX(sf::RenderWindow &window_, GameRNG &game_rng_);
    void drawTopBarElement(const sf::Texture &texture, sf::Sprite &sprite, sf::Sprite &sprite_back, float x_pos, float scale, int value, int card_change) const;
    void draw(int mouseX);
};



#endif //TOPBARGFX_H
