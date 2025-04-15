//
// Created by floron on 4/9/25.
//

#include "../headers/ScreenManager.h"

ScreenManager::ScreenManager(sf::RenderWindow &window_): window(window_), menu_screen(window_, this), game_screen(window_) {
    current_screen = Menu;
    this->setScreen(Menu);
    window.setMouseCursorVisible(true);
}

void ScreenManager::setScreen(const Screen screen) {
    current_screen = screen;
}

ScreenManager::Screen ScreenManager::getCurrentScreen() const {
    return current_screen;
}

void ScreenManager::drawScreen() {
    switch (current_screen) {
        case Menu:
            menu_screen.drawScreen();
            break;
        case Game:
            game_screen.drawScreen();
            break;
        case Settings:
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager) {
    ScreenManager::Screen current_screen = screen_manager.getCurrentScreen();
    os << "Game is currently running on the screen: ";

    switch (current_screen) {
        case 0:
            os << "Menu";
            break;
        case 1:
            os << "Settings";
            break;
        case 2:
            os << "Game";
            break;
    }

    os << std::endl;

    return os;
}