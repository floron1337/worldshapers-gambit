//
// Created by floron on 4/9/25.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>

#include "GameScreen.h"
#include "MenuScreen.h"

class ScreenManager {
public:
    enum Screen {
        Menu,
        Settings,
        Game,
    };
private:
    sf::RenderWindow &window;
    Screen current_screen;
    MenuScreen menu_screen;
    GameScreen game_screen;

public:
    explicit ScreenManager(sf::RenderWindow &window_);
    void setScreen(Screen screen);
    Screen getCurrentScreen() const;
    void drawScreen();
};



#endif //SCREENMANAGER_H
