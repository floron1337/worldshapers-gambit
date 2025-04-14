//
// Created by floron on 4/11/25.
//

#ifndef CARDGFX_H
#define CARDGFX_H

#include <SFML/Graphics.hpp>
#include "Card.h"

class CardGFX {
public:
    enum SwipeDirection {
        Left,
        Right,
    };
private:
    sf::RenderWindow &window;
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

    SwipeDirection swipe_direction = Left;
    float swipe_posX = 0;

    float flip_progress = 1.0f;
    bool showing_back_side = true;

    enum GFXState {
        Idle,
        ChangingCard,
        Flipping,
    } gfx_state = Idle;

    void drawIdleCard(float mouseX);
    void drawChangingCardAnimation(SwipeDirection direction);
    void drawFlipAnimation();

public:
    CardGFX(sf::RenderWindow &window_, sf::Font& card_font_, float card_posX_, float card_posY_);
    void setCard(const Card& card_);
    void setNextCard(const Card& card_);
    void reloadCardTextures();
    void draw(float mouseX);

    void triggerCardChange(SwipeDirection direction);
    void triggerFlip();
};



#endif //CARDGFX_H
