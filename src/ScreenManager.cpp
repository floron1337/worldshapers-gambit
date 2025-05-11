//
// Created by floron on 4/9/25.
//

#include "../headers/ScreenManager.h"
#include "../headers/GameScreen.h"
#include "../headers/SettingsScreen.h"
#include <iostream>

#include "../headers/Constants.h"

ScreenManager::ScreenManager(sf::RenderWindow &window_): window(window_) {
    current_screen_type = Constants::ScreensEnum::Menu;
    this->changeScreen(Constants::ScreensEnum::Menu);
    window.setMouseCursorVisible(true);
}

void ScreenManager::changeScreen(Constants::ScreensEnum screen) {
    switch (screen) {
        case Constants::ScreensEnum::Menu:
        {
            std::unique_ptr<Screen> new_screen(new MenuScreen(&window, this));
            current_screen.reset();
            current_screen = std::move(new_screen);
            break;
        }
        case Constants::ScreensEnum::Settings:
        {
            std::unique_ptr<Screen> new_screen(new SettingsScreen(&window, this));
            current_screen.reset();
            current_screen = std::move(new_screen);
            break;
        }
        case Constants::ScreensEnum::Game:
        {
            std::unique_ptr<Screen> new_screen(new GameScreen(&window, this));
            current_screen.reset();
            current_screen = std::move(new_screen);
            break;
        }
        default:
        {
            std::cout << "Tried to change to an invalid Screen";
            break;
        }
    }
}

Constants::ScreensEnum ScreenManager::getCurrentScreen() const {
    return current_screen_type;
}

void ScreenManager::drawScreen() const {
    current_screen->drawScreen();
}

std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager) {
    Constants::ScreensEnum current_screen = screen_manager.getCurrentScreen();
    os << "Game is currently running on the screen: ";

    switch (current_screen) {
        case Constants::ScreensEnum::Menu:
            os << "Menu";
            break;
        case Constants::ScreensEnum::Settings:
            os << "Settings";
            break;
        case Constants::ScreensEnum::Game:
            os << "Game";
            break;
    }

    os << std::endl;

    return os;
}