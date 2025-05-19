//
// Created by floron on 4/11/25.
//

#ifndef CARDGFX_H
#define CARDGFX_H

#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Constants.h"
#include "GameRNG.h"
#include "SoundManager.h"

class GameRNG;
class CardGFX {
    GameRNG &game_rng;
    sf::RenderWindow &window;

    SoundManager* sound_manager;

    sf::Font &card_font;

    Card current_card;
    Card next_card;

    sf::Texture card_front_texture;
    sf::Sprite card_front_sprite;

    sf::Texture next_card_front_texture;
    sf::Texture next_card_back_texture;
    sf::Sprite next_card_sprite;

    float card_posX = 0;
    float card_posY = 0;

    Constants::SwipeDirection swipe_direction = Constants::Left;
    float swipe_posX = 0;

    float flip_progress = 1.0f;
    bool showing_back_side = true;

    Constants::GFXState gfx_state = Constants::Idle;

    void drawIdleCard(float mouseX);
    void drawChangingCardAnimation(Constants::SwipeDirection direction);
    void drawFlipAnimation();

public:
    CardGFX(sf::RenderWindow &window, GameRNG &game_rng_, SoundManager* sound_manager_, sf::Font& card_font_, float card_posX_, float card_posY_);
    void reloadCardTextures();
    void draw(float mouseX);

    void triggerCardChange(Constants::SwipeDirection direction);
    void triggerFlip();

    bool isIdle() const;
};



#endif //CARDGFX_H
