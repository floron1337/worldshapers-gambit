//
// Created by floron on 4/9/25.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "GameScreen.h"
#include "MenuScreen.h"

class ScreenManager {
public:
    enum CurrentScreenEnum {
        Menu,
        Settings,
        Game,
    };
private:
    sf::RenderWindow &window;
    CurrentScreenEnum current_screen_type;
    std::unique_ptr<Screen> current_screen;

public:
    explicit ScreenManager(sf::RenderWindow &window_);
    void changeScreen(CurrentScreenEnum screen);
    [[nodiscard]] CurrentScreenEnum getCurrentScreen() const;
    void drawScreen() const;

    friend std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager);
};

#endif //SCREENMANAGER_H
