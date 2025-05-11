//
// Created by floron on 4/9/25.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "MenuScreen.h"

class ScreenManager {
    sf::RenderWindow &window;
    Constants::ScreensEnum current_screen_type;
    std::unique_ptr<Screen> current_screen;

public:
    explicit ScreenManager(sf::RenderWindow &window_);
    void changeScreen(Constants::ScreensEnum screen);
    [[nodiscard]] Constants::ScreensEnum getCurrentScreen() const;
    void drawScreen() const;

    friend std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager);
};

#endif //SCREENMANAGER_H
