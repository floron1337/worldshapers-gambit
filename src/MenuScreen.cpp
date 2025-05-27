#include "../headers/MenuScreen.h"
#include "../headers/Button.h"
#include "../headers/ScreenManager.h"

#include <iostream>

MenuScreen::MenuScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_): Screen(window_, screen_manager_) {
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


void MenuScreen::drawScreen() {
    int windowX = window->getSize().x;
    int windowY = window->getSize().y;

    background_sprite.setScale(
        float(windowX) / background_texture.getSize().x,
        float(windowY) / background_texture.getSize().y
    );

    window->draw(background_sprite);

    sf::Text menu_title("Worldshaper's Gambit", monospace_font_bold, 64); // a font is required to make a text object
    menu_title.setFillColor(sf::Color::White);

    // Center the text in the window
    sf::FloatRect text_bounds = menu_title.getLocalBounds();
    menu_title.setOrigin(text_bounds.width / 2.0f, text_bounds.height / 2.0f); // Set the origin to the center of the text
    menu_title.setPosition(windowX / 2.0f, windowY / 2.0f - 100); // Move the text to the center of the window
    window->draw(menu_title);

    Button play_btn("Begin", windowX / 2.0f, windowY / 2.0f + 50, 300.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(play_btn.getShape());
    window->draw(play_btn.getText());

    Button settings_button("Settings", windowX / 2.0f, windowY / 2.0f + 150, 300.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(settings_button.getShape());
    window->draw(settings_button.getText());

    Button exit_button("End it", windowX / 2.0f, windowY / 2.0f + 250, 300.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(exit_button.getShape());
    window->draw(exit_button.getText());

    sf::Event event{};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
            return;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (play_btn.getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                screen_manager->changeScreen(Constants::ScreensEnum::Game);
                return;
            }
            if (settings_button.getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                screen_manager->changeScreen(Constants::ScreensEnum::Settings);
                return;
            }
            if (exit_button.getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                window->close();
                return;
            }

        }
    }

}
