//
// Created by floron on 5/22/25.
//

#ifndef SCREENFACTORY_H
#define SCREENFACTORY_H
#include "Constants.h"
#include "Screen.h"


class ScreenFactory {
public:
    static std::unique_ptr<Screen> createScreen(Constants::ScreensEnum screen_type, sf::RenderWindow &window, ScreenManager *screen_manager);
};



#endif //SCREENFACTORY_H
