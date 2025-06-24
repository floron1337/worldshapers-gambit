//
// Created by floron on 5/12/25.
//

#include "../headers/EndingScreen.h"
#include "../headers/ScreenManager.h"
#include "../headers/Button.h"
#include "../headers/Constants.h"

#include <iostream>

EndingScreen::EndingScreen(sf::RenderWindow *window_, ScreenManager *screen_manager_): Screen(window_, screen_manager_) {
    ending_type = screen_manager_->getEndingType();
    monospace_font = screen_manager->getFontCache().get("./fonts/VeraMono.ttf");
    monospace_font_bold = screen_manager->getFontCache().get("./fonts/VeraMoBd.ttf");

    std::string ending_background;
    switch (screen_manager_->getEndingType()) {
        case Constants::EndingType::OldAge:
            ending_background = "old_age_ending_background.png";
            break;
        case Constants::EndingType::Eclipse:
            ending_background = "eclipse_ending_background.png";
            break;
        case Constants::EndingType::Assasination:
            ending_background = "assasination_ending_background.png";
            break;
        case Constants::EndingType::Omniterra:
            ending_background = "omniterra_ending_background.png";
            break;
        case Constants::EndingType::Cult:
            ending_background = "cult_ending_background.png";
            break;
        case Constants::EndingType::Resignation:
            ending_background = "resignation_ending_background.png";
            break;
        case Constants::EndingType::Legion:
            ending_background = "legion_ending_background.png";
            break;
        case Constants::EndingType::None:
            ending_background = "game_background.png";
            break;
        default:
            ending_background = "game_background.png";
            break;
    }

    if (!background_texture.loadFromFile("./images/" + ending_background)) {
        std::cerr << "Failed to load background image" << std::endl;
        return;
    }
    background_sprite.setTexture(background_texture);
    ending_text1_str = getEndingText1();
    ending_text2_str = getEndingText2();
    ending_text3_str = getEndingText3();
}

// TODO: pune text pentru celelalte ending-uri
std::string EndingScreen::getEndingText1() const {
    switch (ending_type) {
        case Constants::EndingType::OldAge:
            return "The world is a much better place, now that";
        case Constants::EndingType::Eclipse:
            return "The world is a much better place, now that";
        case Constants::EndingType::Assasination:
            return "The world is a much better place, now that";
        case Constants::EndingType::Omniterra:
            return "The world is a much better place, now that";
        case Constants::EndingType::Cult:
            return "The world is a much better place, now that";
        case Constants::EndingType::Resignation:
            return "The world is a much better place, now that";
        case Constants::EndingType::Legion:
            return "The world is a much better place, now that";
        case Constants::EndingType::None:
            return "No ending text.";
        default:
            return "No ending text specified";
    }
}

std::string EndingScreen::getEndingText2() const {
    switch (ending_type) {
        case Constants::EndingType::OldAge:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Eclipse:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Assasination:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Omniterra:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Cult:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Resignation:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::Legion:
            return "your legacy is just a fading memory.";
        case Constants::EndingType::None:
            return "";
        default:
            return "";
    }
}

std::string EndingScreen::getEndingText3() const {
    std::string ending_text = "ENDING: ";
    switch (ending_type) {
        case Constants::EndingType::OldAge:
            ending_text += "OLD AGE";
            break;
        case Constants::EndingType::Eclipse:
            ending_text += "THE ECLIPSE GAMBIT";
            break;
        case Constants::EndingType::Assasination:
            ending_text += "ASSASINATION";
            break;
        case Constants::EndingType::Omniterra:
            ending_text += "THE OMNITERRA GAMBIT";
            break;
        case Constants::EndingType::Cult:
            ending_text += "THE CULT'S GAMBIT";
            break;
        case Constants::EndingType::Resignation:
            ending_text += "RESIGNATION";
            break;
        case Constants::EndingType::Legion:
            ending_text += "THE LEGION'S GAMBIT";
            break;
        case Constants::EndingType::None:
            ending_text += "CONGRATS, YOU'VE BROKEN THE GAME";
            std::cerr << "No ending type specified" << std::endl;
            break;
        default:
            ending_text += "UNKNOWN ENDING TYPE";
            std::cerr << "Unknown ending type: " << ending_type << std::endl;
            break;
    }
    return ending_text;
}

void EndingScreen::drawEndingText() const {
    int windowX = window->getSize().x;
    int windowY = window->getSize().y;

    sf::Text ending_text(ending_text1_str, monospace_font, 44); // a font is required to make a text object
    ending_text.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds = ending_text.getLocalBounds();
    ending_text.setOrigin(ending_text_bounds.width / 2.0f, ending_text_bounds.height / 2.0f); // Set the origin to the center of the text
    ending_text.setPosition(windowX / 2.0f, windowY / 2.0f + 200); // Move the text to the center of the window
    window->draw(ending_text);

    sf::Text ending_text2(ending_text2_str, monospace_font, 44); // a font is required to make a text object
    ending_text2.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds2 = ending_text2.getLocalBounds();
    ending_text2.setOrigin(ending_text_bounds2.width / 2.0f, ending_text_bounds2.height / 2.0f); // Set the origin to the center of the text
    ending_text2.setPosition(windowX / 2.0f, windowY / 2.0f + 250); // Move the text to the center of the window
    window->draw(ending_text2);

    sf::Text ending_text3(ending_text3_str, monospace_font_bold, 32); // a font is required to make a text object
    ending_text3.setFillColor(sf::Color::White);
    sf::FloatRect ending_text_bounds3 = ending_text3.getLocalBounds();
    ending_text3.setOrigin(ending_text_bounds3.width / 2.0f, ending_text_bounds3.height / 2.0f); // Set the origin to the center of the text
    ending_text3.setPosition(windowX / 2.0f, windowY - 100); // Move the text to the center of the window
    window->draw(ending_text3);
}

void EndingScreen::drawScreen() {
    int windowX = window->getSize().x;
    int windowY = window->getSize().y;

    background_sprite.setScale(
        float(windowX) / background_texture.getSize().x,
        float(windowY) / background_texture.getSize().y
    );
    window->draw(background_sprite);

    drawEndingText();

    Button menu_button("End it", windowX / 2.0f, windowY / 2.0f + 350, 300.0f, 75.0f, monospace_font, 32, sf::Color::Black, sf::Color::White);
    window->draw(menu_button.getShape());
    window->draw(menu_button.getText());

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