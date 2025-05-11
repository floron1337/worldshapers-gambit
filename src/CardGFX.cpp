//
// Created by floron on 4/11/25.
//

#include <utility>
#include <iostream>
#include <thread>

#include "../headers/CardGFX.h"

CardGFX::CardGFX(sf::RenderWindow &window_,
                 GameRNG &game_rng_,
                 sf::Font& card_font_,
                 float card_posX_,
                 float card_posY_)
    : game_rng(game_rng_), window(window_), // matches order in class
      card_font(card_font_) // matches order in class
{
    card_posX = card_posX_;
    card_posY = card_posY_;
    gfx_state = Constants::Idle;

    reloadCardTextures();
}

void CardGFX::drawFlipAnimation() {
    if (flip_progress <= 0.0f && showing_back_side) {
        showing_back_side = !showing_back_side;
    }

    if (flip_progress <= -1.0f) {
        flip_progress = 1.0f;
        showing_back_side = false;
        gfx_state = Constants::Idle;

        // TODO: in punctul asta ar trebui sa fie apelat generatorul de carduri
        game_rng.nextCard(Constants::Left);
        reloadCardTextures();

        return;
    }

    int windowX = window.getSize().x;
    int windowY = window.getSize().y;

    float visualScaleX = std::abs(flip_progress);
    visualScaleX = std::clamp(visualScaleX, 0.0f, 1.0f);
    visualScaleX *= 0.65f;

    next_card_sprite.setTexture(showing_back_side ? next_card_back_texture : next_card_front_texture);
    next_card_sprite.setScale(visualScaleX, 0.65f);
    next_card_sprite.setOrigin(next_card_sprite.getLocalBounds().width / 2.f, next_card_sprite.getLocalBounds().height / 2.f);
    next_card_sprite.setPosition(windowX / 2.0f, card_posY);
    window.draw(next_card_sprite);

    flip_progress -= 0.05f;
}

void CardGFX::drawChangingCardAnimation(Constants::SwipeDirection direction) {
    int windowX = window.getSize().x;
    int windowY = window.getSize().y;

    if (swipe_posX > 2 * windowX || swipe_posX < -windowX) {
        triggerFlip();
        return;
    }

    sf::Text card_text(current_card.getText(), card_font, 24);
    card_text.setFillColor(sf::Color::White);
    sf::FloatRect card_text_bounds = card_text.getLocalBounds();
    card_text.setOrigin(
        card_text_bounds.left + card_text_bounds.width / 2.0f,
        card_text_bounds.top + card_text_bounds.height / 2.0f
    );
    card_text.setPosition(card_posX, card_posY - windowY / 2.75f);
    window.draw(card_text);

    next_card_sprite.setScale(0.65f, 0.65f);
    sf::FloatRect next_card_bounds = next_card_sprite.getLocalBounds();
    next_card_sprite.setOrigin(next_card_bounds.width / 2.f, next_card_bounds.height / 2.f);
    next_card_sprite.setPosition(card_posX, card_posY);
    window.draw(next_card_sprite);

    int diffX = swipe_posX - (windowX / 2);

    float offsetX = swipe_posX - diffX * 0.6f;

    int newY = card_posY + std::abs(swipe_posX - windowX / 2) / 3;
    float rotationAngle = diffX * 0.02f;

    card_front_sprite.setScale(0.65f, 0.65f);
    sf::FloatRect card_front_bounds = card_front_sprite.getLocalBounds();
    card_front_sprite.setOrigin(card_front_bounds.width / 2.f, card_front_bounds.height / 2.f);
    card_front_sprite.setPosition(offsetX, newY);
    card_front_sprite.setRotation(rotationAngle);
    window.draw(card_front_sprite);

    if (direction == Constants::SwipeDirection::Left) {
        swipe_posX -= windowX / 25.0f;
    }
    else {
        swipe_posX += windowX / 25.0f;
    }
}

void CardGFX::triggerCardChange(Constants::SwipeDirection direction) {
    swipe_direction = direction;
    swipe_posX = card_posX;
    gfx_state = Constants::GFXState::ChangingCard;
}

void CardGFX::triggerFlip() {
    flip_progress = 1.0f;
    showing_back_side = true;
    gfx_state = Constants::GFXState::Flipping;
}

void CardGFX::drawIdleCard(float mouseX) {
    int windowX = window.getSize().x;
    int windowY = window.getSize().y;

    sf::Text card_text(current_card.getText(), card_font, 24);
    card_text.setFillColor(sf::Color::White);
    sf::FloatRect card_text_bounds = card_text.getLocalBounds();
    card_text.setOrigin(
        card_text_bounds.left + card_text_bounds.width / 2.0f,
        card_text_bounds.top + card_text_bounds.height / 2.0f
    );
    card_text.setPosition(card_posX, card_posY - windowY / 2.75f);
    window.draw(card_text);

    next_card_sprite.setScale(0.65f, 0.65f);
    sf::FloatRect next_card_bounds = next_card_sprite.getLocalBounds();
    next_card_sprite.setOrigin(next_card_bounds.width / 2.f, next_card_bounds.height / 2.f);
    next_card_sprite.setPosition(card_posX, card_posY);
    window.draw(next_card_sprite);


    int diffX = mouseX - (windowX / 2);

    float offsetX = mouseX - diffX * 0.6f;

    float minX = windowX / 3.f;
    float maxX = windowX - windowX / 3.f;
    if (offsetX < minX) offsetX = minX;
    if (offsetX > maxX) offsetX = maxX;

    int newY = card_posY + std::abs(mouseX - windowX / 2) / 8;
    float rotationAngle = diffX * 0.02f;

    card_front_sprite.setScale(0.65f, 0.65f);
    sf::FloatRect card_front_bounds = card_front_sprite.getLocalBounds();
    card_front_sprite.setOrigin(card_front_bounds.width / 2.f, card_front_bounds.height / 2.f);
    card_front_sprite.setPosition(offsetX, newY);
    card_front_sprite.setRotation(rotationAngle);
    window.draw(card_front_sprite);
}

void CardGFX::draw(float mouseX) {
    switch (gfx_state) {
        case Constants::GFXState::Idle:
            drawIdleCard(mouseX);
            break;
        case Constants::GFXState::ChangingCard:
            drawChangingCardAnimation(swipe_direction);
            break;
        case Constants::GFXState::Flipping:
            drawFlipAnimation();
            break;
        default:
            std::cerr << "Invalid state" << std::endl;
    }
}

void CardGFX::reloadCardTextures() {
    current_card = game_rng.getCurrentCard();
    next_card = game_rng.getNextCard();

    std::string cards_location = "./images/cards/";

    if (!card_front_texture.loadFromFile(cards_location + current_card.getFrontLocation())) {
        std::cerr << "Failed to load texture!" << std::endl;
    }
    if (!next_card_front_texture.loadFromFile(cards_location + next_card.getFrontLocation())) {
        std::cerr << "Failed to load texture!" << std::endl;
    }
    if (!next_card_back_texture.loadFromFile(cards_location + game_rng.getCurrentPackCardBackLocation())) {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    card_front_sprite.setTexture(card_front_texture);
    next_card_sprite.setTexture(next_card_back_texture);
}

void CardGFX::setCard(const Card &card_) {
    current_card = card_;
}

void CardGFX::setNextCard(const Card &card_) {
    next_card = card_;
}

bool CardGFX::isIdle() const {
    if (gfx_state == Constants::GFXState::Idle)
        return true;

    return false;
}
