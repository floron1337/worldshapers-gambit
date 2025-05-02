//
// Created by floron on 4/9/25.
//

#include "../headers/ScreenManager.h"
#include <iostream>

ScreenManager::ScreenManager(sf::RenderWindow &window_): window(window_) {
    current_screen_type = Menu;
    this->changeScreen(Menu);
    window.setMouseCursorVisible(true);
}

void ScreenManager::changeScreen(CurrentScreenEnum screen) {
    switch (screen) {
        case Menu:
        {
            std::unique_ptr<Screen> new_screen(new MenuScreen(window, this));
            current_screen.reset();
            current_screen = move(new_screen);
            break;
        }
        case Settings:
        {
            std::cout << "Tried to change to Settings Screen, which is not yet implemented.";
            break;
        }
        case Game:
        {
            std::unique_ptr<Screen> new_screen_game(new GameScreen(window, this));
            current_screen.reset();
            current_screen = move(new_screen_game);
            break;
        }
        default:
        {
            std::cout << "Tried to change to an invalid Screen";
            break;
        }
    }
}

ScreenManager::CurrentScreenEnum ScreenManager::getCurrentScreen() const {
    return current_screen_type;
}

void ScreenManager::drawScreen() const {
    current_screen->drawScreen();
}

std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager) {
    ScreenManager::CurrentScreenEnum current_screen = screen_manager.getCurrentScreen();
    os << "Game is currently running on the screen: ";

    switch (current_screen) {
        case ScreenManager::Menu:
            os << "Menu";
            break;
        case ScreenManager::Settings:
            os << "Settings";
            break;
        case ScreenManager::Game:
            os << "Game";
            break;
    }

    os << std::endl;

    return os;
}