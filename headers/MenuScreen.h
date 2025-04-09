#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML/Graphics.hpp>

class ScreenManager;

class MenuScreen {
    sf::Font monospace_font;
    sf::Font monospace_font_bold;
    sf::Sprite background_sprite;
    sf::Texture background_texture;

    sf::RenderWindow &window;
    ScreenManager *screen_manager;

public:
    explicit MenuScreen(sf::RenderWindow &window_, ScreenManager *screen_manager_);
    void drawScreen();
};

#endif //MENUSCREEN_H
