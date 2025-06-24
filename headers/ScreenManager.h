//
// Created by floron on 4/9/25.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Constants.h"
#include "MenuScreen.h"
#include "ResourceCache.h"
#include "SoundManager.h"

class ScreenManager {
    sf::RenderWindow &window;
    Constants::ScreensEnum current_screen_type;
    std::unique_ptr<Screen> current_screen;
    Constants::EndingType ending_type = Constants::EndingType::None;
    SoundManager &sound_manager;
    ResourceCache<sf::Font> font_cache;

public:
    explicit ScreenManager(sf::RenderWindow &window_, SoundManager &sound_manager_);
    void changeScreen(Constants::ScreensEnum screen);
    [[nodiscard]] Constants::ScreensEnum getCurrentScreen() const;
    void drawScreen() const;
    [[nodiscard]] Constants::EndingType getEndingType() const;
    void setEndingType(Constants::EndingType ending_type_);
    [[nodiscard]] SoundManager* getSoundManager() const;
    ResourceCache<sf::Font>& getFontCache() { return font_cache; }

    friend std::ostream& operator<<(std::ostream& os, const ScreenManager& screen_manager);
};

#endif //SCREENMANAGER_H
