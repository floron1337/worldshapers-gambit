#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
class ScreenManager;

class MenuScreen : public Screen{
public:
    explicit MenuScreen(sf::RenderWindow &window_, ScreenManager *screen_manager_);
    void drawScreen() override;
};

#endif //MENUSCREEN_H
