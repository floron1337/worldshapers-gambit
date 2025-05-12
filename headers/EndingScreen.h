//
// Created by floron on 5/12/25.
//

#ifndef ENDINGSCREEN_H
#define ENDINGSCREEN_H
#include "Screen.h"
#include <SFML/Graphics.hpp>

class ScreenManager;

class EndingScreen : public Screen{
public:
    explicit EndingScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_);
    void drawScreen() override;
};



#endif //ENDINGSCREEN_H
