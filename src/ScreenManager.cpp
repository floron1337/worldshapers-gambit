//
// Created by floron on 4/9/25.
//

#include "../headers/Constants.h"
#include "../headers/ScreenManager.h"
#include "../headers/ScreenFactory.h"
#include "../headers/GameScreen.h"
#include <iostream>

ScreenManager::ScreenManager(sf::RenderWindow &window_, SoundManager* sound_manager_): window(window_), sound_manager(sound_manager_) {
    current_screen_type = Constants::ScreensEnum::Menu;
    this->changeScreen(Constants::ScreensEnum::Menu);
    window.setMouseCursorVisible(true);
}

void ScreenManager::changeScreen(Constants::ScreensEnum screen) {
    std::unique_ptr<Screen> new_screen = ScreenFactory::createScreen(screen, window, this);

    if (auto* game_screen = dynamic_cast<GameScreen*>(new_screen.get())) {
        game_screen->setLastMouseX(sf::Mouse::getPosition(window).x);
    }

    current_screen = std::move(new_screen);
}

Constants::ScreensEnum ScreenManager::getCurrentScreen() const {
    return current_screen_type;
}

void ScreenManager::drawScreen() const {
    current_screen->drawScreen();
}

std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager) {
    const Constants::ScreensEnum current_screen = screen_manager.getCurrentScreen();
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
        case Constants::ScreensEnum::Ending:
            os << "Ending";
    }

    os << std::endl;

    return os;
}

Constants::EndingType ScreenManager::getEndingType() const {
    return ending_type;
}

void ScreenManager::setEndingType(Constants::EndingType ending_type_) {
    ending_type = ending_type_;
}

SoundManager* ScreenManager::getSoundManager() const {
    return sound_manager;
}

