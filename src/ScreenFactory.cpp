//
// Created by floron on 5/22/25.
//

#include "../headers/ScreenFactory.h"
#include "../headers/MenuScreen.h"
#include "../headers/GameScreen.h"
#include "../headers/SettingsScreen.h"
#include "../headers/EndingScreen.h"
#include "../headers/Exception.h"

std::unique_ptr<Screen> ScreenFactory::createScreen(const Constants::ScreensEnum screen_type, sf::RenderWindow &window, ScreenManager *screen_manager) {
    switch (screen_type) {
        case Constants::ScreensEnum::Menu:
        {
            return std::make_unique<MenuScreen>(&window, screen_manager);
        }
        case Constants::ScreensEnum::Settings:
        {
            return std::make_unique<SettingsScreen>(&window, screen_manager);
        }
        case Constants::ScreensEnum::Game:
        {
            return std::make_unique<GameScreen>(&window, screen_manager);
        }
        case Constants::ScreensEnum::Ending:
        {
            return std::make_unique<EndingScreen>(&window, screen_manager);
        }
        default:
        {
            throw InvalidScreenId(screen_type);
        }
    }
}

