//
// Created by floron on 4/9/25.
//

#include "../headers/GameScreen.h"
#include <iostream>

#include "../headers/ScreenManager.h"
#include "../headers/Screen.h"

GameScreen::GameScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_): Screen(window_, screen_manager_),
                                                                                   game_rng(Constants::GAME_DATA_PACKS_LOCATION), cardGFX(*window_,game_rng, monospace_font, window->getSize().x / 2.0f, window->getSize().y / 2.0f + 100), topBarGFX(*window_, game_rng) {
    last_mouse_x = 0;

    if (!monospace_font.loadFromFile("./fonts/MonospaceBold.ttf")) {
        std::cerr << "Failed to load monospace font" << std::endl;
        return;
    }

    if (!background_texture.loadFromFile("./images/game_background.png")) {
        std::cerr << "Failed to load background image" << std::endl;
        return;
    }
    background_sprite.setTexture(background_texture);
}

void GameScreen::setLastMouseX(int x) {
    last_mouse_x = x;
}

void GameScreen::drawScreen() {
    int windowX = window->getSize().x;
    int windowY = window->getSize().y;

    background_sprite.setScale(
        float(windowX) / background_texture.getSize().x,
        float(windowY) / background_texture.getSize().y
    );
    window->draw(background_sprite);

    sf::RectangleShape bg_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, windowY - 100));
    bg_rect.setFillColor(sf::Color::Black); // Set button background color
    bg_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    bg_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    bg_rect.setOrigin(bg_rect.getSize() / 2.0f);
    bg_rect.setPosition(windowX / 2.0f, windowY / 2.0f - 15);
    window->draw(bg_rect);

    sf::RectangleShape top_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, 100));
    top_rect.setFillColor(sf::Color::Black); // Set button background color
    top_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    top_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    top_rect.setOrigin(top_rect.getSize() / 2.0f);
    top_rect.setPosition(windowX / 2.0f, 85);
    window->draw(top_rect);

    sf::RectangleShape bottom_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, 50));
    bottom_rect.setFillColor(sf::Color::Black); // Set button background color
    bottom_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    bottom_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    bottom_rect.setOrigin(bottom_rect.getSize() / 2.0f);
    bottom_rect.setPosition(windowX / 2.0f, windowY - 85);
    window->draw(bottom_rect);

    sf::Text bottom_text("YOU ARE RESPONSIBLE FOR THIS. YOU MUST DECIDE.", monospace_font, 24); // a font is required to make a text object
    bottom_text.setFillColor(sf::Color::White);
    sf::FloatRect bottom_text_bounds = bottom_text.getLocalBounds();
    bottom_text.setOrigin(
        bottom_text_bounds.left + bottom_text_bounds.width / 2.0f,
        bottom_text_bounds.top + bottom_text_bounds.height / 2.0f
    );
    bottom_text.setPosition(windowX / 2.0f, windowY - 85); // Move the text to the center of the window
    window->draw(bottom_text);

    std::string years_in_power_str = std::to_string(game_rng.getYearsInPower()) + " " + (game_rng.getYearsInPower() == 1 ? "year" : "years") + " in power";
    sf::Text years_in_power_text(years_in_power_str, monospace_font, 44);
    years_in_power_text.setFillColor(sf::Color::White);
    sf::FloatRect years_in_power_text_bounds = years_in_power_text.getLocalBounds();
    years_in_power_text.setOrigin(
        years_in_power_text_bounds.left + years_in_power_text_bounds.width / 2.0f,
        years_in_power_text_bounds.top + years_in_power_text_bounds.height / 2.0f
    );
    years_in_power_text.setPosition(250, windowY - 85);
    window->draw(years_in_power_text);

    int mouseX = -1;

    sf::Event event{};
    while (window->pollEvent(event)) {
        if (cardGFX.isIdle() && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (event.mouseButton.x < (windowX - windowX / 4.0f) / 2.0f)
                cardGFX.triggerCardChange(Constants::SwipeDirection::Left);
            else if (event.mouseButton.x > (windowX + windowX / 4.0f) / 2.0f)
                cardGFX.triggerCardChange(Constants::SwipeDirection::Right);
        }
        else if (event.type == sf::Event::MouseMoved) {
            mouseX = event.mouseMove.x;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            auto current_pack = game_rng.getCurrentPack();
            std::cout << current_pack.isFinalPack() << std::endl;
            std::cout << current_pack.getPackCardBackLocation() << std::endl;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            screen_manager->changeScreen(Constants::ScreensEnum::Menu);
            return;
        }
    }

    if (mouseX == -1)
        mouseX = last_mouse_x;


    cardGFX.draw(mouseX);
    topBarGFX.draw(mouseX);

    setLastMouseX(mouseX);

    if (game_rng.hasGameEnded()) {
        endGame();
    }
}

void GameScreen::endGame() const {
    screen_manager->setEndingType(Constants::EndingType::Eclipse);
    screen_manager->changeScreen(Constants::ScreensEnum::Ending);
}

