//
// Created by floron on 4/9/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>

#include "CardGFX.h"

class GameScreen {
    sf::Font monospace_font;
    sf::Sprite background_sprite;
    sf::Texture background_texture;

    sf::RenderWindow &window;
    int last_mouse_x;

    CardGFX cardGFX;

public:
    explicit GameScreen(sf::RenderWindow &window_);
    void drawScreen();
    void setLastMouseX(int x);
};



#endif //GAMESCREEN_H
