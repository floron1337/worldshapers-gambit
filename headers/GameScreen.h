//
// Created by floron on 4/9/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>

#include "CardGFX.h"
#include "GameRNG.h"
#include "Screen.h"

class GameScreen : public Screen{
    int last_mouse_x;
    CardGFX cardGFX;
    GameRNG game_rng;

public:
    explicit GameScreen(sf::RenderWindow &window_, ScreenManager *screen_manager_);
    void drawScreen() override;
    void setLastMouseX(int x);
};



#endif //GAMESCREEN_H
