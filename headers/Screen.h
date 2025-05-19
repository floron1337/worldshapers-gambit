//
// Created by floron on 5/2/25.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

#include "SoundManager.h"

class ScreenManager;

class Screen {
protected:
    sf::Font monospace_font;
    sf::Font monospace_font_bold;
    sf::Sprite background_sprite;
    sf::Texture background_texture;

    sf::RenderWindow *window;
    ScreenManager *screen_manager;
public:
    explicit Screen(sf::RenderWindow *window_, ScreenManager *screen_manager_);
    virtual ~Screen() = default;
    Screen& operator= (const Screen& other);
    Screen(const Screen& other);

    virtual void drawScreen() = 0;
};



#endif //SCREEN_H
