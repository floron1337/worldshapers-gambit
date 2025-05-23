//
// Created by floron on 5/22/25.
//

#ifndef MUSICMENUGFX_H
#define MUSICMENUGFX_H
#include "SoundManager.h"
#include <SFML/Graphics.hpp>


class MusicMenuGFX {
    bool menu_open = false;
    sf::RenderWindow &window;
    SoundManager *sound_manager;

    sf::Sprite music_button_sprite;
    sf::Texture music_button_texture;

    void drawMenu();
    void drawButton();
public:
    MusicMenuGFX(sf::RenderWindow &window_, SoundManager *sound_manager_);
    void drawMusicMenu();
};



#endif //MUSICMENUGFX_H
