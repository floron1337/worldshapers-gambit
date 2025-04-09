#include "../headers/MenuScreen.h"

#include <iostream>

MenuScreen::MenuScreen() {
    if (!monospace_font.loadFromFile("../fonts/VeraMono.ttf")) {
        std::cerr << "Failed to load monospace font" << std::endl;
        return;
    }
}


void MenuScreen::drawScreen(sf::RenderWindow &window) {
    int windowX = window.getSize().x;
    int windowY = window.getSize().y;

    sf::Text menu_title("Worldshaper's Gambit", monospace_font, 64); // a font is required to make a text object

    menu_title.setFillColor(sf::Color::White);

    // Center the text in the window
    sf::FloatRect text_bounds = menu_title.getLocalBounds();
    menu_title.setOrigin(text_bounds.width / 2.0f, text_bounds.height / 2.0f); // Set the origin to the center of the text
    menu_title.setPosition(windowX / 2.0f, windowY / 2.0f - 200); // Move the text to the center of the window

    window.draw(menu_title);

    // Create a button background
    sf::RectangleShape play_button(sf::Vector2f(200.0f, 50.0f)); // Size: 200x50
    play_button.setFillColor(sf::Color::White); // Set button background color
    play_button.setPosition((windowX - play_button.getSize().x) / 2.0f, windowY / 2 - 50); // Center horizontally, adjust vertically

    // Create button text
    sf::Text play_text("Begin", monospace_font, 30); // Button label
    play_text.setFillColor(sf::Color::Black);
    sf::FloatRect play_text_bounds = play_text.getLocalBounds();
    play_text.setOrigin(play_text_bounds.width / 2.0f, play_text_bounds.height / 2.0f); // Center the text within its bounds
    play_text.setPosition(play_button.getPosition().x + play_button.getSize().x / 2.0f,
                           play_button.getPosition().y + play_button.getSize().y / 2.0f - 5); // Center text in the button

    // Draw the button background and text
    window.draw(play_button);
    window.draw(play_text);

    sf::RectangleShape exit_button(sf::Vector2f(200.0f, 50.0f)); // Size: 200x50
    exit_button.setFillColor(sf::Color::White); // Set button background color
    exit_button.setPosition((windowX - exit_button.getSize().x) / 2.0f, windowY / 2 + 50); // Center horizontally, adjust vertically

    // Create button text
    sf::Text exit_text("End it.", monospace_font, 30); // Button label
    exit_text.setFillColor(sf::Color::Black);
    sf::FloatRect exit_text_bounds = exit_text.getLocalBounds();
    exit_text.setOrigin(exit_text_bounds.width / 2.0f, exit_text_bounds.height / 2.0f); // Center the text within its bounds
    exit_text.setPosition(exit_button.getPosition().x + exit_button.getSize().x / 2.0f,
                           exit_button.getPosition().y + exit_button.getSize().y / 2.0f - 10); // Center text in the button

    window.draw(exit_button);
    window.draw(exit_text);

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (play_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                // Play button clicked
                std::cout << "Play button clicked" << std::endl;
            else if (exit_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                window.close();
        }
    }
}