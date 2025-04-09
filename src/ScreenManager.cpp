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



