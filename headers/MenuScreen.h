#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML/Graphics.hpp>

class MenuScreen {
    sf::Font monospace_font;
public:
    MenuScreen();
    void drawScreen(sf::RenderWindow &window);
};

#endif //MENUSCREEN_H
