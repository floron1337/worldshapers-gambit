#include "../headers/Game.h"
#include "../headers/ScreenManager.h"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Game::Game() {
    this->max_fps = 60;
}

Game::Game(int max_fps_) {
    this->max_fps = max_fps_;
}

Game::~Game() = default;

void Game::start() const {
    // Get the desktop resolution
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Create a window covering the entire screen
    sf::RenderWindow window(desktop, "Worldshaper's Gambit", sf::Style::Fullscreen);
    window.setFramerateLimit(this->max_fps);

    ScreenManager screen_manager(window);

    // COD INUTIL MOMENTAN CA SA NU PLANGA CPPCHECK
    // UTIL MAI TARZIU
    ScreenManager::Screen current_screen = screen_manager.getCurrentScreen();
    if (current_screen == ScreenManager::Menu) {
        std::cout << screen_manager << std::endl;
    }
    // ######################

    // screen_manager.setScreen(ScreenManager::Game);

    while (window.isOpen())
    {
        window.clear();
        screen_manager.drawScreen();
        window.display();
    }
}