#include "../headers/Game.h"
#include "../headers/ScreenManager.h"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../headers/SoundManager.h"

Game::Game() {
    this->max_fps = 60;
}

Game::Game(int max_fps_) {
    this->max_fps = max_fps_;
}

Game::~Game() = default;

void Game::start() const {
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(desktop, "Worldshaper's Gambit", sf::Style::Fullscreen);
    window.setFramerateLimit(this->max_fps);

    SoundManager sound_manager;
    ScreenManager screen_manager(window, &sound_manager);

    sound_manager.loadMusic(Constants::MUSIC_LOCATION);
    //sound_manager.playMusic(0);
    //screen_manager.changeScreen(Constants::ScreensEnum::Game);

    while (window.isOpen())
    {
        window.clear();
        screen_manager.drawScreen();
        window.display();
    }
}