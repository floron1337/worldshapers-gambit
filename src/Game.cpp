#include "../headers/Game.h"
#include "../headers/ScreenManager.h"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../headers/SoundManager.h"

Game::Game(unsigned max_fps_) : max_fps(max_fps_), window(sf::VideoMode::getDesktopMode(), "Worldshaper's Gambit", sf::Style::Fullscreen),
                           sound_manager(50.0f), screen_manager(window, sound_manager) {
    window.setFramerateLimit(max_fps);
}

Game::~Game() = default;

Game* Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

void Game::start(){
    //screen_manager.changeScreen(Constants::ScreensEnum::Game);
    sound_manager.playMusic(1);

    while (window.isOpen())
    {
        window.clear();
        screen_manager.drawScreen();
        window.display();
    }
}