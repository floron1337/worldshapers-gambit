//
// Created by floron on 4/9/25.
//

#include "../headers/GameScreen.h"
#include <iostream>

GameScreen::GameScreen(sf::RenderWindow &window_): window(window_){
    last_mouse_x = 0;
    if (!monospace_font.loadFromFile("../fonts/MonospaceBold.ttf")) {
        std::cerr << "Failed to load monospace font" << std::endl;
        return;
    }

    if (!background_texture.loadFromFile("../images/game_background.png")) {
        std::cerr << "Failed to load background image" << std::endl;
        return;
    }
    background_sprite.setTexture(background_texture);
}

void GameScreen::setLastMouseX(int x) {
    last_mouse_x = x;
}


void GameScreen::drawScreen() {
    int windowX = window.getSize().x;
    int windowY = window.getSize().y;

    background_sprite.setScale(
        float(windowX) / background_texture.getSize().x,
        float(windowY) / background_texture.getSize().y
    );
    window.draw(background_sprite);

    sf::RectangleShape bg_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, windowY - 100));
    bg_rect.setFillColor(sf::Color::Black); // Set button background color
    bg_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    bg_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    bg_rect.setOrigin(bg_rect.getSize() / 2.0f);
    bg_rect.setPosition(windowX / 2.0f, windowY / 2.0f - 15);
    window.draw(bg_rect);

    sf::RectangleShape top_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, 100));
    top_rect.setFillColor(sf::Color::Black); // Set button background color
    top_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    top_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    top_rect.setOrigin(top_rect.getSize() / 2.0f);
    top_rect.setPosition(windowX / 2.0f, 85);
    window.draw(top_rect);

    sf::RectangleShape bottom_rect = sf::RectangleShape(sf::Vector2f(windowX / 2.5f, 50));
    bottom_rect.setFillColor(sf::Color::Black); // Set button background color
    bottom_rect.setOutlineThickness(2.0f);          // Adds the border thickness
    bottom_rect.setOutlineColor(sf::Color::White);  // Sets the border color
    bottom_rect.setOrigin(bottom_rect.getSize() / 2.0f);
    bottom_rect.setPosition(windowX / 2.0f, windowY - 85);
    window.draw(bottom_rect);

    sf::Text bottom_text("YOU ARE RESPONSIBLE FOR THIS. YOU MUST DECIDE.", monospace_font, 24); // a font is required to make a text object
    bottom_text.setFillColor(sf::Color::White);
    sf::FloatRect bottom_text_bounds = bottom_text.getLocalBounds();
    bottom_text.setOrigin(
        bottom_text_bounds.left + bottom_text_bounds.width / 2.0f,
        bottom_text_bounds.top + bottom_text_bounds.height / 2.0f
    );
    bottom_text.setPosition(windowX / 2.0f, windowY - 85); // Move the text to the center of the window
    window.draw(bottom_text);


    int newX = -1;

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

        }
        else if (event.type == sf::Event::MouseMoved) {
            //std::cout << "Mouse moved" << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
            newX = event.mouseMove.x;
        }
    }

    // TODO: MOVE THIS LOGIC
    sf::Text card_text("Ai fost ales liderul Echipei Planeta.\nAccepti?", monospace_font, 24); // a font is required to make a text object
    card_text.setFillColor(sf::Color::White);
    sf::FloatRect card_text_bounds = card_text.getLocalBounds();
    card_text.setOrigin(
        card_text_bounds.left + card_text_bounds.width / 2.0f,
        card_text_bounds.top + card_text_bounds.height / 2.0f
    );
    card_text.setPosition(windowX / 2.0f, 215); // Move the text to the center of the window
    window.draw(card_text);

    sf::Texture card_texture;
    if (!card_texture.loadFromFile("../images/cards/tron.png")) {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(card_texture);
    sprite.setScale(0.65f, 0.65f);
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    if (newX == -1)
        newX = last_mouse_x;

    int diffX = newX - (windowX / 2);

    float offsetX = newX - diffX * 0.6f;

    float minX = windowX / 3.f;
    float maxX = windowX - windowX / 3.f;
    if (offsetX < minX) offsetX = minX;
    if (offsetX > maxX) offsetX = maxX;


    int newY = std::abs(newX - windowX / 2);
    float rotationAngle = diffX * 0.02f;

    sprite.setPosition(offsetX, windowY / 2.0f + newY / 8);
    sprite.setRotation(rotationAngle);
    window.draw(sprite);
    setLastMouseX(newX);
}
