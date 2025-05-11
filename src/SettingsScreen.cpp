//
// Created by floron on 5/11/25.
//

#include "../headers/SettingsScreen.h"
#include "../headers/Button.h"
#include "../headers/Constants.h"
#include "../headers/ScreenManager.h"

#include <iostream>

SettingsScreen::SettingsScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_) : Screen(window_, screen_manager_) {
    if (!monospace_font.loadFromFile("./fonts/VeraMono.ttf")) {
        std::cerr << "Failed to load monospace font" << std::endl;
        return;
    }

    if (!monospace_font_bold.loadFromFile("./fonts/VeraMoBd.ttf")) {
        std::cerr << "Failed to load monospace bold font" << std::endl;
        return;
    }

    if (!background_texture.loadFromFile("./images/menu_background.png")) {
        std::cerr << "Failed to load background image" << std::endl;
        return;
    }
    background_sprite.setTexture(background_texture);
}

void SettingsScreen::drawScreen() {
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

    sf::Text top_text("SETTINGS", monospace_font, 32); // a font is required to make a text object
    top_text.setFillColor(sf::Color::White);
    sf::FloatRect top_text_bounds = top_text.getLocalBounds();
    top_text.setOrigin(
        top_text_bounds.left + top_text_bounds.width / 2.0f,
        top_text_bounds.top + top_text_bounds.height / 2.0f
    );
    top_text.setPosition(windowX / 2.0f, 85.0f); // Move the text to the center of the window
    window->draw(top_text);

    Button back_btn("<", windowX / 2.5f - 145   , 85, 75.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(back_btn.getShape());
    window->draw(back_btn.getText());

    sf::Text wip_text("WORK IN PROGRESS", monospace_font, 32); // a font is required to make a text object
    wip_text.setFillColor(sf::Color::White);
    sf::FloatRect wip_text_bounds = wip_text.getLocalBounds();
    wip_text.setOrigin(
        wip_text_bounds.left + wip_text_bounds.width / 2.0f,
        wip_text_bounds.top + wip_text_bounds.height / 2.0f
    );
    wip_text.setPosition(windowX / 2.0f, windowY / 2.0f); // Move the text to the center of the window
    window->draw(wip_text);

    sf::Event event{};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (back_btn.getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                screen_manager->changeScreen(Constants::ScreensEnum::Menu);
            }
        }
    }
}
