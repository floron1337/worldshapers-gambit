#include "../headers/Game.h"
#include "../headers/MenuScreen.h"
#include "../headers/GameScreen.h"

#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../headers/ScreenManager.h"


Game::Game() {
    this->max_fps = 60;
}

Game::Game(int max_fps_) {
    this->max_fps = max_fps_;
}

Game::~Game() = default;

void Game::start() {
    // Get the desktop resolution
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Create a window covering the entire screen
    sf::RenderWindow window(desktop, "Worldshaper's Gambit", sf::Style::Fullscreen);
    window.setFramerateLimit(this->max_fps);

    ScreenManager screen_manager(window);
    screen_manager.setScreen(ScreenManager::Menu);

    while (window.isOpen())
    {
        window.clear();

        screen_manager.drawScreen();

        //using namespace std::chrono_literals;
        //std::this_thread::sleep_for(300ms);

        window.display();
    }
}