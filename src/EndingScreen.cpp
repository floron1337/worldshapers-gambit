//
// Created by floron on 5/12/25.
//

#include "../headers/EndingScreen.h"
#include "../headers/ScreenManager.h"
#include "../headers/Button.h"

#include <iostream>

EndingScreen::EndingScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_): Screen(window_, screen_manager_) {
    if (!monospace_font.loadFromFile("./fonts/VeraMono.ttf")) {
        std::cerr << "Failed to load monospace font" << std::endl;
        return;
    }

    if (!monospace_font_bold.loadFromFile("./fonts/VeraMoBd.ttf")) {
        std::cerr << "Failed to load monospace bold font" << std::endl;
        return;
    }

    if (!background_texture.loadFromFile("./images/eclipse_ending_background.png")) {
        std::cerr << "Failed to load background image" << std::endl;
        return;
    }
    background_sprite.setTexture(background_texture);
}

void EndingScreen::drawScreen() {
    int windowX = window->getSize().x;
    int windowY = window->getSize().y;

    background_sprite.setScale(
        float(windowX) / background_texture.getSize().x,
        float(windowY) / background_texture.getSize().y
    );
    window->draw(background_sprite);

    sf::Text ending_text("The world is a much better place, now that", monospace_font, 44); // a font is required to make a text object
    ending_text.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds = ending_text.getLocalBounds();
    ending_text.setOrigin(ending_text_bounds.width / 2.0f, ending_text_bounds.height / 2.0f); // Set the origin to the center of the text
    ending_text.setPosition(windowX / 2.0f, windowY / 2.0f + 200); // Move the text to the center of the window
    window->draw(ending_text);

    sf::Text ending_text2("your legacy is just a fading memory.", monospace_font, 44); // a font is required to make a text object
    ending_text2.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds2 = ending_text2.getLocalBounds();
    ending_text2.setOrigin(ending_text_bounds2.width / 2.0f, ending_text_bounds2.height / 2.0f); // Set the origin to the center of the text
    ending_text2.setPosition(windowX / 2.0f, windowY / 2.0f + 250); // Move the text to the center of the window
    window->draw(ending_text2);

    Button menu_button("End it", windowX / 2.0f, windowY / 2.0f + 350, 300.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(menu_button.getShape());
    window->draw(menu_button.getText());

    sf::Text ending_text3("ENDING: THE ECLIPSE GAMBIT", monospace_font_bold, 32); // a font is required to make a text object
    ending_text3.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds3 = ending_text3.getLocalBounds();
    ending_text3.setOrigin(ending_text_bounds3.width / 2.0f, ending_text_bounds3.height / 2.0f); // Set the origin to the center of the text
    ending_text3.setPosition(windowX / 2.0f, windowY - 100); // Move the text to the center of the window
    window->draw(ending_text3);

    sf::Event event{};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            screen_manager->changeScreen(Constants::ScreensEnum::Menu);
            return;
        }
        if (menu_button.getShape().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            screen_manager->changeScreen(Constants::ScreensEnum::Menu);
            return;
        }
    }
};